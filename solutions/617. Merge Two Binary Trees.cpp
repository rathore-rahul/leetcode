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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL)
            return NULL;
        else if(t1 == NULL)
            return t2;
        else if(t2 == NULL)
            return t1;
        TreeNode* x = new TreeNode(0);
        x->val = t1->val + t2->val;
        x->left = mergeTrees(t1->left, t2->left);
        x->right = mergeTrees(t1->right,t2->right);
        return x;
    }
};
