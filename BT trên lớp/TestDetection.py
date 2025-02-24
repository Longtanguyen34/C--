import cv2
import numpy as np

def detect_shapes(frame):
    # Chuyển ảnh sang grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    # Làm mượt ảnh để giảm nhiễu
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    
    # Phát hiện cạnh sử dụng Canny
    edges = cv2.Canny(blurred, 50, 150)
    
    # Tìm các đường viền (Contours)
    contours, _ = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    
    for contour in contours:
        # Bỏ qua các đường viền quá nhỏ
        if cv2.contourArea(contour) < 500:
            continue
        
        # Xấp xỉ đa giác (polygon approximation)
        epsilon = 0.02 * cv2.arcLength(contour, True)
        approx = cv2.approxPolyDP(contour, epsilon, True)
        
        # Vẽ đường viền trên ảnh
        cv2.drawContours(frame, [approx], -1, (0, 255, 0), 2)
        
        # Nhận diện hình dạng dựa trên số đỉnh của đa giác
        shape = "Undefined"
        num_vertices = len(approx)
        
        if num_vertices == 3:
            shape = "Triangle"
        elif num_vertices == 4:
            # Kiểm tra hình vuông hay hình chữ nhật
            x, y, w, h = cv2.boundingRect(approx)
            aspect_ratio = w / float(h)
            if 0.95 <= aspect_ratio <= 1.05:
                shape = "Square"
            else:
                shape = "Rectangle"
        elif num_vertices > 5:
            shape = "Circle"
        
        # Tìm vị trí trung tâm để hiển thị tên hình dạng
        M = cv2.moments(contour)
        if M["m00"] != 0:
            cX = int(M["m10"] / M["m00"])
            cY = int(M["m01"] / M["m00"])
            cv2.putText(frame, shape, (cX - 50, cY), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)
    
    return frame

# Khởi động camera
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break
    
    # Nhận diện hình dạng
    frame_with_shapes = detect_shapes(frame)
    
    # Hiển thị video
    cv2.imshow("Shape Detection", frame_with_shapes)
    
    # Nhấn 'q' để thoát
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Cannot access the camera")

# Giải phóng tài nguyên
cap.release()
cv2.destroyAllWindows()
