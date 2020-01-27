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
    bool isBalanced(TreeNode* root) {
        return height(root) < 0 ? false : true; 
    }
    int height(TreeNode* root){
        if(root == NULL)
            return  0;
        int l = height(root->left);
        int r = height(root->right);
        if( abs(l-r) > 1 || l == -1 || r == -1)
            return -1;
        return max(l,r)+1;
    }
};
