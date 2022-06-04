# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, num, root):
        if root.left == None and root.right == None:
            self.result = num*10+root.val
        if root.left != None:
            self.dfs(num*10+root.val, root.left)
        if root.right != None:
            self.dfs(num*10+root.val, root.right)
    def sumRootToLeaf(self, root):
        self.result = 0
        self.dfs(0, root)
        return self.result
