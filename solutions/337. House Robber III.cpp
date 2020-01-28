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
    int rob(TreeNode* root) {
        pair<int,int> result =  helper(root);
        return max(result.first, result.second);
    }
    
    pair<int,int> helper(TreeNode* root){
        if(root == NULL)
            return {0,0};
        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);
        pair<int,int> result = {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
        return result;
    }
};
