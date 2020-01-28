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
    int left, right;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        find(root,x);
        int red = max(left,max(right, n-left-right-1));
        if(red > n/2)
           return true;
         return false;
    }
    
    void find(TreeNode* root, const int& x){
        if(root){
            if(root->val == x){
                left = count(root->left);
                right = count(root->right);
                return;
            }
            find(root->left,x);
            find(root->right,x);
        }
    }
    
    int count(TreeNode* root){
        if(root == NULL)
            return 0;
        return count(root->left) + count(root->right) + 1;
    }
};
