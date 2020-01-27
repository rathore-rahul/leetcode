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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> curr;
        curr.push(root);
        while(!curr.empty()){
            double sum = 0;
            int count = 0;
            queue<TreeNode*> next;
            while(!curr.empty()){
                TreeNode * t = curr.front();
                curr.pop();
                sum += t->val;
                count++;
                if(t->left)
                    next.push(t->left);
                if(t->right)
                    next.push(t->right);
            }
            result.push_back(sum/count);
            curr.swap(next);
        }
        return result;
    }
};
