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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root,0).first;
    }
    
    pair<TreeNode*,int> helper(TreeNode* root,  int depth){
        if(!root || (!root->left && !root->right))
            return {root,depth};
        pair<TreeNode*,int> left = helper(root->left,depth+1);
        pair<TreeNode*,int> right = helper(root->right,depth+1);
        if(!left.first)
            return right;
        else if(!right.first)
            return left;
        else if(left.second == right.second)
            return {root, left.second};
        else if(left.second > right.second)
            return left;
        return right;
            
    }
};
