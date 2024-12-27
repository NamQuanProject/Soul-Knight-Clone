from PIL import Image

def resize_image(input_path, output_path, scale_factor):
    """
    Resizes an image to a smaller version of itself.

    Args:
        input_path (str): Path to the input image.
        output_path (str): Path to save the resized image.
        scale_factor (float): Factor by which to scale the image (e.g., 0.5 for half size).
    """
    try:
        # Open the image
        image = Image.open(input_path, "r")
        print(f"Original dimensions: {image.size}")

        # Calculate new dimensions
        new_width = int(image.width * scale_factor)
        new_height = int(image.height * scale_factor)

        # Resize the image
        resized_image = image.resize((new_width, new_height), Image.LANCZOS)
        print(f"Resized dimensions: {resized_image.size}")

        # Save the resized image
        resized_image.save(output_path)
        print(f"Resized image saved to: {output_path}")

    except Exception as e:
        print(f"Error: {e}")

# Example usage
input_path = "Knight_16_starter.png"
output_path = "knight_skill.bmp"
scale_factor = 0.1 # Resize to 50% of the original size

resize_image(input_path, output_path, scale_factor)
