from bs4 import BeautifulSoup

# Read the content from the file
with open('map_xml/3.1.xml', 'r') as file:
    html_content = file.read()

# Parse the HTML content
soup = BeautifulSoup(html_content, 'html.parser')

# Find all <area> tags with title="wall"
area_tags = soup.find_all('area', title="wall")

# Extract and print the relevant information
for tag in area_tags:
    coords = tag.get('coords')
    x1, y1, x2, y2 = coords.split(",")
    alt = tag.get('alt')
    title = tag.get('title')
    print(f"AddWall(Point({x1}, {y1}), Point({x2}, {y2}));")
