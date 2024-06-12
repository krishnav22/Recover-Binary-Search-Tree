# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self,root,first,middle,last,prev):
        if root:
            self.solve(root.left,first,middle,last,prev)
            if prev[0] and root.val<prev[0].val:
                
                if not first[0]:
                    first[0] = prev[0]
                    middle[0] = root
                
                else:
                    last[0] = root
            prev[0] = root
            self.solve(root.right,first,middle,last,prev)
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        first = [None]
        middle = [None]
        last = [None]
        prev = [None]
        self.solve(root,first,middle,last,prev)
        if first[0] and last[0]:
            first[0].val,last[0].val = last[0].val,first[0].val
        elif first[0] and middle[0]:
            first[0].val,middle[0].val = middle[0].val,first[0].val
        
