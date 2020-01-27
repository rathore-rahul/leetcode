/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int val = 0;
        helper(root,val);
        return val;
    }
    int helper(TreeNode* root, int& a){
        if(!root)
            return -1;
        int left = helper(root->left,a)+1;
        int right = helper(root->right,a)+1;
        a = max(left+right,a);
        return max(left,right);
    }
};
