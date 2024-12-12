import cv2
import numpy as np
from PIL import Image
import os

def read_gif_with_opencv(gif_path):
    # Open the gif with Pillow
    gif = Image.open(gif_path)
    
    frames = []
    
    # Loop through each frame of the gif (only up to 4 frames)
    for _ in range(4):
        # Convert each frame to an OpenCV-compatible format (numpy array)
        frame = np.array(gif.convert("RGB"))  # Convert to RGB format
        frame = cv2.cvtColor(frame, cv2.COLOR_RGB2BGR)  # Convert from RGB to BGR for OpenCV
        
        frames.append(frame)
        
        # Try to go to the next frame
        try:
            gif.seek(gif.tell() + 1)
        except EOFError:
            break
    
    return frames

# Path to the gif file
gif_path = "Robot_8_emp.gif"

# Get the frames of the gif (only the first 4 frames)
frames = read_gif_with_opencv(gif_path)

# Directory to save the frames
output_dir = "frames_output"
os.makedirs(output_dir, exist_ok=True)  # Create directory if it doesn't exist

# Save the first four frames as separate images
for i, frame in enumerate(frames):
    output_path = os.path.join(output_dir, f"frame_{i+1}.bmp")
    cv2.imwrite(output_path, frame)

# Show a message once the frames are saved
print(f"First four frames have been saved in {output_dir}.")
