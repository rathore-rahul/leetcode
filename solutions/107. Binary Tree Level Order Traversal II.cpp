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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        stack<vector<int> > temp;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        int pre = 0, next = 0;
        q.push(root);
        pre++;
        vector<int> curr;
        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();
            pre--;
            if(t->left){
                q.push(t->left);next++;
            }
            if(t->right){
                q.push(t->right);next++;
            }
            curr.push_back(t->val);
            if(pre == 0){
                pre = next;
                next = 0;
                temp.push(curr);
                curr.clear();
            }
        }
        while(!temp.empty()){
            result.push_back(temp.top());
            temp.pop();
        }
        return result;
    }
};
