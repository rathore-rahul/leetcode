/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
#define exist(x, cover) cover.find(x) != cover.end()
​
class Solution {
public:
    int ans = 0;
    set<TreeNode*> cover;
    int minCameraCover(TreeNode* root) {
        cover.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
    void dfs(TreeNode* root, TreeNode* par){
        if(root){
            dfs(root->left,root);
            dfs(root->right,root);
            if((par == NULL && !(exist(root,cover))) || (!(exist(root->left,cover))) || (!(exist(root->right,cover)))){
                ans++;
                cover.insert(root);
                cover.insert(root->left);
                cover.insert(root->right);
                cover.insert(par);
            }
        }
    }
};
