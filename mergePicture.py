import cv2
import numpy as np
import os


content_path = os.path.join('resources', 'map', '3-1.bmp')  # Image with the subject
background_path = os.path.join('map_xml', 'AddBackground2.png')  # Image with the background


content_image = cv2.imread(content_path)  
background_image = cv2.imread(background_path)  

if content_image is None:
    raise FileNotFoundError(f"Content image not found at {content_path}")
if background_image is None:
    raise FileNotFoundError(f"Background image not found at {background_path}")

content_image = cv2.resize(content_image, (background_image.shape[1], background_image.shape[0]))


white_mask = cv2.inRange(content_image, (200, 200, 200), (255, 255, 255))  # Adjust thresholds for near-white


subject_mask = cv2.bitwise_not(white_mask)


subject = cv2.bitwise_and(content_image, content_image, mask=subject_mask)

background_for_white = cv2.bitwise_and(background_image, background_image, mask=white_mask)


merged_image = cv2.add(subject, background_for_white)


output_path = 'merged_image.bmp'


cv2.imwrite(output_path, merged_image)
cv2.imshow('Merged Image', merged_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
