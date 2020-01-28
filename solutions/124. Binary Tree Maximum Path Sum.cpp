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
    int max_path(TreeNode* root, int & res){
        if(root == NULL)
            return 0;
        int l = max(0,max_path(root->left,res));
        int r = max(0,max_path(root->right,res));
        res = max(res,l+r+root->val);
        return max(l+root->val,r+root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        max_path(root,res);
        return res;
    }
};
