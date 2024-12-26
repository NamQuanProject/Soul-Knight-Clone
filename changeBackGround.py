import cv2
import numpy as np

# Load the image
image = cv2.imread('resources/player/wukong/4.bmp')  # Replace with your image file path

# Check if the image was loaded successfully
if image is None:
    print("Error: Image not found!")
    exit()

# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Create a mask where the black background is
_, mask = cv2.threshold(gray, 10, 255, cv2.THRESH_BINARY)

# Invert the mask
mask_inv = cv2.bitwise_not(mask)

# Create a white background
white_background = np.full_like(image, 255)

# Combine the white background with the original image using the mask
foreground = cv2.bitwise_and(image, image, mask=mask)
background = cv2.bitwise_and(white_background, white_background, mask=mask_inv)
result = cv2.add(foreground, background)

# Save the result
cv2.imwrite('resources/player/wukong/4.bmp', result)


