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
    bool isCousins(TreeNode* root, int x, int y) {
        int px=-1,py=-1,dx=-1,dy=-1,curr=0;
        if(root == NULL)
            return false;
        helper(root,x,y,px,py,dx,dy,curr);
        if(px == -1 || py == -1 || dx != dy || px == py)
            return false;
        return true;
    }
    void helper(TreeNode* root, int &x, int &y, int &px, int &py, int &dx, int &dy,int curr){
        if(root == NULL)
            return;
        if( (root->left && root->left->val == x) || (root->right && root->right->val == x)) {
            px = root->val; dx = curr+1;
        }
        if( (root->left && root->left->val == y) || (root->right && root->right->val == y)){
            py = root->val; dy = curr+1;
        }
        helper(root->left,x,y,px,py,dx,dy,curr+1);
        helper(root->right,x,y,px,py,dx,dy,curr+1);
    }
};
