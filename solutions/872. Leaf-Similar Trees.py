# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
​
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def inorder(root):
            if not root:
                return []
            elif not root.left and not root.right:
                return [root.val]
            else:
                return inorder(root.left) + inorder(root.right)
        l1 = inorder(root1)
        l2 = inorder(root2)
        return l1 == l2
