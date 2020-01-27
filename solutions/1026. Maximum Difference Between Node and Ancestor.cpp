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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, -1e9, 1e9);
    }
    
    int helper(TreeNode* root, int max_, int min_){
        if(root == NULL)
            return 0;
        max_ = max(max_,root->val);
        min_ = min(min_, root->val);
        if(!root->left && !root->right){
            return abs(max_ - min_);
        }
        return max(helper(root->left, max_, min_), helper(root->right, max_, min_));
    }
};
