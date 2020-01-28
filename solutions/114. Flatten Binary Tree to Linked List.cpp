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
    void flatten(TreeNode* root) {
        if(root)
            helper(root);
    }
    TreeNode* helper(TreeNode* root){
        if(!root->left && !root->right)
            return root;
        else if(!root->left)
            return helper(root->right);
        else if(!root->right){
            root->right = root->left;
            root->left = NULL;
            return helper(root->right);
        }
        TreeNode* lTail = helper(root->left);
        TreeNode* rTail = helper(root->right);
        lTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return rTail;
    }
};
