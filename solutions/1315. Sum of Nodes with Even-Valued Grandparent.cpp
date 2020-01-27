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
    int sumEvenGrandparent(TreeNode* root) {
        vector<int> path;
        return helper(root,path);
    }
    
    int helper(TreeNode* root, vector<int>& path){
        if(root == NULL)
            return 0;
        int count = 0;
        if(path.size() >=2 && path[path.size()-2]%2 == 0)
            count += root->val;
        path.push_back(root->val);
        count += helper(root->left,path);
        count += helper(root->right,path);
        path.pop_back();
        return count;
    }
};
