import os

def generate_directory_structure(root_dir, marker="└──", indent="    "):
    output = []

    def walk_dir(current_dir, depth=0):
        entries = sorted(os.listdir(current_dir))
        entries = [e for e in entries if not e.startswith(".")]

        for i, entry in enumerate(entries):
            path = os.path.join(current_dir, entry)
            is_last = (i == len(entries) - 1)
            prefix = marker if is_last else "├──"
            output.append(f"{indent * depth}{prefix} {entry}")

            if os.path.isdir(path):
                walk_dir(path, depth + 1)

    output.append(f"{os.path.basename(root_dir)}/")
    walk_dir(root_dir)

    return "\n".join(output)

root_directory = "src"
directory_structure = generate_directory_structure(root_directory)

output_file = "SoulKnight_Structure.txt"
with open(output_file, "w") as file:
    file.write(directory_structure)

print(f"Directory structure saved to {output_file}")
from PIL import Image, ImageDraw, ImageFont

def text_to_image(text, output_image="directory_structure.png", font_path="/path/to/font.ttf", font_size=16):
    lines = text.split("\n")
    font = ImageFont.truetype(font_path, font_size)  # Use a TTF font
    max_width = max(len(line) for line in lines) * font_size // 2
    max_height = len(lines) * font_size

    # Create an image with a white background
    image = Image.new("RGB", (max_width, max_height), "white")
    draw = ImageDraw.Draw(image)

    # Write text onto the image
    for i, line in enumerate(lines):
        draw.text((10, i * font_size), line, fill="black", font=font)

    image.save(output_image)
    print(f"Directory structure image saved to {output_image}")

# Provide the path to a TTF font file
font_path = "/System/Library/Fonts/Supplemental/Arial.ttf"  # Example for macOS
# Read the text file and convert it to an image
with open("SoulKnight_Structure.txt", "r") as file:
    directory_text = file.read()

text_to_image(directory_text, font_path=font_path)
