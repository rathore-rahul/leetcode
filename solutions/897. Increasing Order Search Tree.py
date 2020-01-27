# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
​
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(root):
            if not root:
                return []
            return inorder(root.left) + [root] + inorder(root.right)
        l = inorder(root)
        for i in range(len(l)):
            l[i].left = None
            if i != len(l)-1:
                l[i].right = l[i+1]
            else:
                l[i].right = None
        return l[0]
