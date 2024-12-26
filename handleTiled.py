from PIL import Image

def split_png_to_bmp(png_path, points, output_prefix):
    """
    Splits a PNG image into BMP files based on given points.

    Args:
        png_path (str): Path to the PNG file.
        points (list): List of tuples containing (top-left, bottom-right) points for each region.
        output_prefix (str): Prefix for the output BMP file names.
    """
    try:
        # Open the PNG file
        image = Image.open(png_path)
        print(f"Image dimensions: {image.size}")

        # Process each region defined by points
        for i, (top_left, bottom_right) in enumerate(points):
            # Crop the image using the points
            cropped = image.crop((*top_left, *bottom_right))
            output_path = f"{i + 1}.bmp"
            
            # Save the cropped region as a BMP file
            cropped.save(output_path, format="BMP")
            print(f"Saved: {output_path}")

    except Exception as e:
        print(f"Error: {e}")

# Path to the large PNG file
png_path = "map.png"

points = [
    ((580, 600), (658, 679)),  # Region 1
    # ((50, 0), (80, 30)),  # Region 2
    # ((0, 40), (30, 70)),  # Region 3
    # ((50, 40), (80, 70)),  # Region 4
]

# Prefix for output BMP files
output_prefix = "/"

# Split the PNG into BMP files
split_png_to_bmp(png_path, points, output_prefix)
