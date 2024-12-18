import cv2
import numpy as np
from PIL import Image
import os

def read_gif_with_opencv(gif_path):
    # Open the gif with Pillow
    gif = Image.open(gif_path)
    
    frames = []

    for _ in range(4):
        frame = np.array(gif.convert("RGB")) 
        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR) 
        
        frames.append(frame)
        
        try:
            gif.seek(gif.tell() + 1)
        except EOFError:
            break
    
    return frames


gif_path = "Robot_8_emp.gif"

frames = read_gif_with_opencv(gif_path)


output_dir = "frames_output"
os.makedirs(output_dir, exist_ok=True)  


for i, frame in enumerate(frames):
    output_path = os.path.join(output_dir, f"frame_{i+1}.bmp")
    cv2.imwrite(output_path, frame)


print(f"First four frames have been saved in {output_dir}.")
