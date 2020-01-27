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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int> & nums, int i, int j){
        // printf("range %d %d\n", i, j);
        if(i > j)
            return NULL;
        int idx = max_element(nums.begin()+i, nums.begin()+j+1)-nums.begin();
        // printf("max %d\n",idx);
        TreeNode* root = new TreeNode(nums[idx]);
        root->left = helper(nums,i,idx-1);
        root->right = helper(nums,idx+1,j);
        return root;
    }
};
