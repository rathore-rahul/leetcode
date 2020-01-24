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
    int sumRootToLeaf(TreeNode* root) {
        int cum_sum = 0;
        helper(root,0,cum_sum);
        return cum_sum;
    }
    void helper(TreeNode* root, int curr, int& cum_sum){
        if(root == NULL)
            return;
        else if(root->left == NULL && root->right == NULL){
            cum_sum += curr*2 + root->val;
            return;
        }
        else{
            helper(root->left, curr*2 + root->val, cum_sum);
            helper(root->right, curr*2 + root->val, cum_sum);
        }
    }
};
​
