"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        out = []
        for child in root.children:
            out = out + self.postorder(child)
        out.append(root.val)
        return out
