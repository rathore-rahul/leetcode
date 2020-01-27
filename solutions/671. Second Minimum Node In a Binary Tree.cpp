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
    void smallest(TreeNode* root, int val, int & minval){
        if(root->val > val && root->val < minval)
            minval = root->val;
        if(root->left != NULL)
            smallest(root->left,val,minval);
        if(root->right != NULL)
            smallest(root->right,val,minval);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int minval = INT_MAX;
        smallest(root,root->val,minval);
        return minval == INT_MAX ? -1 : minval;
    }
};
