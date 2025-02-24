import cv2
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

# Đọc ảnh
image_path = 'Aglaea.jpg'  # Thay bằng đường dẫn đến ảnh
image = cv2.imread(image_path)
image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

# Chuẩn bị dữ liệu
pixel_values = image.reshape((-1, 3))
pixel_values = np.float32(pixel_values)

# Áp dụng k-means clustering
k = 3
kmeans = KMeans(n_clusters=k, random_state=42)
kmeans.fit(pixel_values)

# Gán lại giá trị màu cho từng cluster
centers = np.uint8(kmeans.cluster_centers_)
labels = kmeans.labels_
segmented_image = centers[labels.flatten()]
segmented_image = segmented_image.reshape(image.shape)

# Hiển thị ảnh gốc và ảnh sau phân cụm
plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.title("Original Image")
plt.imshow(image)
plt.axis('off')

plt.subplot(1, 2, 2)
plt.title("Segmented Image with K=3")
plt.imshow(segmented_image)
plt.axis('off')

plt.tight_layout()
plt.show()
