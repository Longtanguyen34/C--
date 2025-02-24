import cv2
import numpy as np
import matplotlib.pyplot as plt

# Đọc ảnh đầu vào
image_path = 'Aglaea.jpg'  # Thay bằng đường dẫn đến ảnh của bạn
image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)  # Đọc ảnh mức xám

# Áp dụng Thresholding
threshold = 128  # Ngưỡng để phân vùng (có thể tùy chỉnh)
_, binary_image = cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)

# Hiển thị kết quả
plt.figure(figsize=(10, 5))

# Ảnh gốc
plt.subplot(1, 2, 1)
plt.title("Original Image")
plt.imshow(image, cmap='gray')
plt.axis('off')

# Ảnh sau Thresholding
plt.subplot(1, 2, 2)
plt.title(f"Thresholding at T={threshold}")
plt.imshow(binary_image, cmap='gray')
plt.axis('off')

plt.tight_layout()
plt.show()
