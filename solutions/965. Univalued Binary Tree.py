# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
​
class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return true;
        return self.helper(root,root.val)
    
    def helper(self,root: TreeNode, val: int) -> bool:
        if not root:
            return True
        return root.val == val and self.helper(root.left,val) and self.helper(root.right,val)
        
