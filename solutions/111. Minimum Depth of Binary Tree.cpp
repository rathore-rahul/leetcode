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
    int minDepth(TreeNode* root) {
       if(root == NULL)
           return 0;
        if(!root->left && !root->right)
            return 1;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l == 0 || r == 0)
            return max(l,r)+1;
        return min(l,r)+1;
    }
};
