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
    TreeNode* convertBST(TreeNode* root) { 
        int curr = 0;
        helper(root, curr);
        return root;
    }
    void helper(TreeNode* root, int& curr){
        if(root == NULL)
            return;
        helper(root->right,curr);
        curr += root->val;
        root->val = curr;
        helper(root->left,curr);
    }
};
