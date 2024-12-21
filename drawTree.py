import os
import networkx as nx
import matplotlib.pyplot as plt
from pathlib import Path

def build_tree_graph(root_dir):
    """
    Build a directed graph representing the directory structure.
    
    Args:
        root_dir (str): Path to the root directory
    Returns:
        nx.DiGraph: Directory structure graph
    """
    G = nx.DiGraph()
    root_path = Path(root_dir).resolve()
    
    if not root_path.exists():
        raise FileNotFoundError(f"Directory not found: {root_path}")
    
    for dirpath, dirnames, filenames in os.walk(root_path):
        rel_dirpath = os.path.relpath(dirpath, root_path)
        if rel_dirpath == '.':
            rel_dirpath = root_path.name
            
        G.add_node(rel_dirpath, type='directory')
        
        for dirname in dirnames:
            rel_child_path = os.path.relpath(os.path.join(dirpath, dirname), root_path)
            G.add_node(rel_child_path, type='directory')
            G.add_edge(rel_dirpath, rel_child_path)
        
        for filename in filenames:
            rel_file_path = os.path.relpath(os.path.join(dirpath, filename), root_path)
            G.add_node(rel_file_path, type='file')
            G.add_edge(rel_dirpath, rel_file_path)
    
    return G

def draw_tree_graph(G, root_dir, output_path=None):
    """
    Draw the directory tree graph and optionally save it to a file.
    
    Args:
        G (nx.DiGraph): Directory structure graph
        root_dir (str): Path to the root directory
        output_path (str, optional): Path to save the image file
    """
    plt.figure(figsize=(20, 12))  # Increased figure size for better resolution
    
    try:
        pos = nx.nx_agraph.graphviz_layout(G, prog="dot", args="-Grankdir=TB -Gnodesep=0.15 -Granksep=0.4")
    except (ImportError, Exception) as e:
        print(f"Falling back to spring layout: {str(e)}")
        pos = nx.spring_layout(G, k=2, iterations=50)
    
    node_types = nx.get_node_attributes(G, 'type')
    
    # Draw directory nodes (smaller size)
    dir_nodes = [node for node in G.nodes() if node_types.get(node) == 'directory']
    nx.draw_networkx_nodes(G, pos,
                          nodelist=dir_nodes,
                          node_color='lightblue',
                          node_size=300,  # Reduced from 1000
                          alpha=0.7)
    
    # Draw file nodes (even smaller)
    file_nodes = [node for node in G.nodes() if node_types.get(node) == 'file']
    nx.draw_networkx_nodes(G, pos,
                          nodelist=file_nodes,
                          node_color='lightgreen',
                          node_size=100,  # Reduced from 500
                          alpha=0.7)
    
    # Draw edges with reduced width
    nx.draw_networkx_edges(G, pos,
                          edge_color='gray',
                          arrows=True,
                          arrowsize=5,  # Reduced from 10
                          width=0.3)  # Reduced from 0.5
    
    # Prepare labels
    labels = {}
    for node in G.nodes():
        if node_types.get(node) == 'directory':
            labels[node] = node
        else:
            labels[node] = Path(node).name
    
    nx.draw_networkx_labels(G, pos,
                           labels=labels,
                           font_size=4,  # Reduced from 6
                           font_weight='bold')
    
    plt.title(f"Directory Tree for {Path(root_dir).name}", pad=20)
    plt.axis('off')
    plt.tight_layout()
    
    # Save the figure if output path is provided
    if output_path:
        plt.savefig(output_path, dpi=300, bbox_inches='tight', format='png')
        print(f"Visualization saved to: {output_path}")
    
    plt.show()
    plt.close()

def main():
    """Main function to run the directory visualization."""
    import argparse
    
    parser = argparse.ArgumentParser(description='Visualize directory structure as a tree graph')
    parser.add_argument('--dir', type=str, required=True, help='Root directory to visualize')
    parser.add_argument('--output', type=str, help='Output image path (e.g., tree.png)')
    args = parser.parse_args()
    
    try:
        tree_graph = build_tree_graph(args.dir)
        draw_tree_graph(tree_graph, args.dir, args.output)
    except Exception as e:
        print(f"Error: {str(e)}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())