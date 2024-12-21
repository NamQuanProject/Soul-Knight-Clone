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
