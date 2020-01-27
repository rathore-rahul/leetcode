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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre,0, pre.size()-1,post,0,post.size()-1);
    }
    TreeNode* helper(vector<int>& pre, int i, int j, vector<int>& post, int k ,int l){
        if(i > j)
            return NULL;
        if(i == j)
            return new TreeNode(pre[i]);
        TreeNode* root = new TreeNode(pre[i]);
        int idx = find(post.begin()+k, post.begin()+l+1, pre[i+1]) - (post.begin()+k);
        root->left = helper(pre,i+1,i+1+idx,post,k,k+idx);
        root->right = helper(pre,i+1+idx+1,j,post,k+idx+1,l-1);
        return root;
        
    }
};
