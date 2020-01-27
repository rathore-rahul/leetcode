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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode * node = new TreeNode(val);
        if(root == NULL)
            return node;
        if(root->val < val){
            node->left = root;
            return node;
        }
        helper(root, val, node);
        return root;
};
TreeNode* helper(TreeNode* root, int val, TreeNode* newNode){
        if(root == NULL)
            return newNode;
        if(root->val >= val){
            root->right = helper(root->right,val,newNode);
            return root;
        }
        newNode->left = root;
        return newNode;
    }
};
    
