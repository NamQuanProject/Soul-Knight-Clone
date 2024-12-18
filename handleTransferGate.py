import cv2
import numpy as np

# Load the image
image = cv2.imread('resources/object/transfer_gate/transfergate.bmp')

# Convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply a threshold to detect light regions (white areas)
_, mask = cv2.threshold(gray, 230, 255, cv2.THRESH_BINARY)

# Replace the white regions in the image with pure white
image[(mask >= 230) & (mask <= 255)] = [255, 255, 255]

# Save or display the result
cv2.imwrite('filtered_image_with_white_replacement.bmp', image)
# cv2.imshow('Filtered Image with White Replacement', image)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
