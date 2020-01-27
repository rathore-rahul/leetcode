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
    bool path(TreeNode* root, int sum ,int curr_sum){
        if(root == NULL)    return false;
        if(root->left == NULL && root->right == NULL) return sum == (curr_sum + root->val);
        return path(root->left,sum,curr_sum + root->val) || path(root->right,sum,curr_sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return path(root,sum,0);
    }
};
