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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        return helper(root->left,1) + helper(root->right,0);
    }
    int helper(TreeNode* root, int a){
        if(root == NULL)
            return 0;
        else if(!root->left && !root->right)
            return root->val * a;
        
        return helper(root->left,1) + helper(root->right,0);
        
    }
};
