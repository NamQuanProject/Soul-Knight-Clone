import cv2
import numpy as np
import os

# Define the file paths
content_path = os.path.join('resources', 'map', '1-1.bmp')  # Image with the subject
background_path = os.path.join('map_xml', 'AddBackground.png')  # Image with the background

# Load the images
content_image = cv2.imread(content_path)  
background_image = cv2.imread(background_path)  

# Check if images are loaded correctly
if content_image is None:
    raise FileNotFoundError(f"Content image not found at {content_path}")
if background_image is None:
    raise FileNotFoundError(f"Background image not found at {background_path}")

# Ensure the images have the same size
content_image = cv2.resize(content_image, (background_image.shape[1], background_image.shape[0]))

# Create a mask for white areas in the content image
white_mask = cv2.inRange(content_image, (200, 200, 200), (255, 255, 255))  # Adjust thresholds for near-white

# Invert the mask to get the subject areas (non-white)
subject_mask = cv2.bitwise_not(white_mask)

# Extract the subject from the content image (non-white regions)
subject = cv2.bitwise_and(content_image, content_image, mask=subject_mask)

# Extract the background for the white areas
background_for_white = cv2.bitwise_and(background_image, background_image, mask=white_mask)

# Combine the subject and the background
merged_image = cv2.add(subject, background_for_white)

# Define the output file path
output_path = 'merged_image.bmp'

# Save and display the result
cv2.imwrite(output_path, merged_image)
cv2.imshow('Merged Image', merged_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
