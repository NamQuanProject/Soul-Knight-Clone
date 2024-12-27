import os
import cv2

def flip_bmp(input_path, output_path):
    image = cv2.imread(input_path)
    image = cv2.flip(image, 1)
    cv2.imwrite(output_path, image)

flip_bmp("resources/start/begin.png", "resources/start/flip_begin.png")


# for root, dirs, files in os.walk('resources/start/'):
#     for file in files:
#         if not any(excluded_dir in root for excluded_dir in ['game', 'start']):
#             input_path = os.path.join(root, file)
#             output_path = os.path.join(root, 'flip_' + file)
#             if not input_path.__contains__('flip_'):
#                 flip_bmp(input_path, output_path)