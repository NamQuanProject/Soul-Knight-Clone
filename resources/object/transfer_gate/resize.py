

from PIL import Image
# Function to resize the image
def resize_image(input_path, output_path, width, height):
    # Open the image
    img = Image.open(input_path)
    
    # Resize the image
    resized_img = img.resize((width, height), Image.Resampling.LANCZOS)
    
    # Save the resized image
    resized_img.save(output_path)
    print(f"Image resized and saved to {output_path}")

# Example usage
input_image_path = "frame_4.bmp"  # Replace with your input image path
output_image_path = "frame_4.bmp"  # Replace with your output image path
resize_width = 116 # Desired width
resize_height = 116  # Desired height

resize_image(input_image_path, output_image_path, resize_width, resize_height)
