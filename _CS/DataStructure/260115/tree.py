class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def print_tree(node, level=0):

    if node is None:
        return
    
    print_tree(node.right, level + 1)
    print('    ' * level + f"-> {node.value}")
    print_tree(node.left, level + 1)

# 루트 노드 생성
root = TreeNode("a")
# 왼쪽, 오른쪽 자식 노드 생성
root.left = TreeNode("b")
root.right = TreeNode("c")

print_tree(root)