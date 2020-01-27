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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> roots;
        if(helper(root, to_delete,roots))
            roots.push_back(root);
        return roots;
    }
    TreeNode* helper(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>&roots){
        if(root == NULL)
            return root;
        TreeNode* left = helper(root->left, to_delete, roots);
        TreeNode* right = helper(root->right,to_delete,roots);
        if(find(to_delete.begin(),to_delete.end(), root->val) != to_delete.end()){
            if(left)
                roots.push_back(left);
            if(right)
                roots.push_back(right);
            return NULL;
        }
        else{
            root->left = left;
            root->right = right;
            return root;
        }
    }
};
