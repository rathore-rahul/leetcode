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
    int pathSum(TreeNode* root, int sum) {
        map<int,int> run;
        run[0] = 1;
        int curr = 0;
        return helper(root, sum, run,curr);
    }
    int helper(TreeNode* root, int sum, map<int,int> &run,int curr){
        if(!root)
            return 0;
        curr = curr + root->val;
        int count;
        if(run.find(curr-sum) != run.end()){
            count = run[curr-sum];
            
        }
        else
            count = 0;
        if(run.find(curr) != run.end()){
            run[curr]++;
        }
        else
            run[curr] = 1;
        int out = count + helper(root->left,sum,run,curr) + helper(root->right,sum,run,curr);
        run[curr]--;
        return out;
    }
};
