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
    int findTilt(TreeNode* root) {
        int a = 0;
        helper(root,a);
        return a;
    }
    int helper(TreeNode* root, int &a){
        if(root == NULL)
            return 0;
        int l = helper(root->left,a);
        int r = helper(root->right,a);
        a += abs(l-r);
        return l+r+root->val;
    }
};
