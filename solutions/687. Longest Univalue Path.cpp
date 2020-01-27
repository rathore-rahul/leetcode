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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL)
            return 0;
        int high = 0;
        helper(root,high,INT_MAX);
        return high;
        
    }
    int helper(TreeNode* root, int& high, int par){
        if(!root)
            return 0;
        int l = helper(root->left,high,root->val);
        int r = helper(root->right,high,root->val);
        high = max(high,l+r);
        if(root->val != par)
            return 0;
        return max(l,r)+1;
    }
};
