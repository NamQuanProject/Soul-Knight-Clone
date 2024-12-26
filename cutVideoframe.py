import cv2
import numpy as np
from PIL import Image
import os

import numpy as np
import cv2
from PIL import Image

def read_gif_with_opencv(gif_path):
    gif = Image.open(gif_path)
    frames = []

    for _ in range(4):
        frame = np.array(gif.convert("RGBA"))
        
        # Convert to BGRA for OpenCV compatibility
        frame_bgr = cv2.cvtColor(frame, cv2.COLOR_RGBA2BGRA)
        
        # Replace transparent pixels (alpha = 0) with white (255, 255, 255)
        # frame_bgr[frame_bgr[:, :, 3] == 0] = [255, 255, 255, 255]
        
        # Convert back to BGR
        frame_bgr = cv2.cvtColor(frame_bgr, cv2.COLOR_BGRA2BGR)
        
        # Resize the frame by dividing the dimensions by 8 with smooth interpolation
        frame_resized = frame_bgr[::10, ::10]

        
        # Append the resized frame to the list
        frames.append(frame_resized)
        
        # Move to the next frame in the GIF
        try:
            gif.seek(gif.tell() + 1)
        except EOFError:
            break

    return frames



gif_path = "Knight_25_dual_wield.png"

frames = read_gif_with_opencv(gif_path)


output_dir = "src/"
os.makedirs(output_dir, exist_ok=True)  


for i, frame in enumerate(frames):
    output_path = os.path.join(output_dir, f"{i+1}.bmp")
    cv2.imwrite(output_path, frame)


print(f"First four frames have been saved in {output_dir}.")
