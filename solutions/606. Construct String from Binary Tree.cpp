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
    string tree2str(TreeNode* t) {
        string s;
        helper(t,s);
        return s;
    }
    void helper(TreeNode* t, string &s){
        if(t == NULL)
            return;
        s += to_string(t->val);
       if(t->left == NULL && t->right == NULL)
           return;
        else if(t->left == NULL){
            s += "()("; helper(t->right,s); s += ')';
        }
        else if(t->right == NULL){
            s += '('; helper(t->left,s); s += ')';
        }
        else{
            s += '('; helper(t->left,s); s+= ')';
            s += '('; helper(t->right,s); s+= ')';
        }
    }
};
