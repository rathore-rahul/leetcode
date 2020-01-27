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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)
            return 0;
        int deepest_level = 0;
        int sum = 0;
        helper(root, 0, deepest_level, sum);
        return sum;
    }
    
    void helper(TreeNode* root, int curr_level, int & deepest_level, int & sum){
        if(!root)
            return;
        if(curr_level > deepest_level){
            deepest_level = curr_level;
            sum = 0;
        }
        if(curr_level == deepest_level)
            sum += root->val;
        helper(root->left, curr_level+1, deepest_level, sum);
        helper(root->right, curr_level+1, deepest_level, sum);
    }
};
