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
    int distributeCoins(TreeNode* root) {
        int result = 0;
        helper(root,result);
        return result;
    }
    int helper(TreeNode* root, int &result){
        if(!root)
            return 0;
        int l = helper(root->left,result);
        int r = helper(root->right,result);
        result += abs(l) + abs(r);
        return l+r+root->val-1;
    }
};
