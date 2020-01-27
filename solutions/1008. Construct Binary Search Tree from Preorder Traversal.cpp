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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,INT_MIN,INT_MAX);
    }
    
    TreeNode* helper(const vector<int>& preorder, int idx, int low, int high){
        TreeNode* node = NULL;
        if(idx >= preorder.size() )
            return node;
        
        while(idx < preorder.size() && (preorder[idx] < low || preorder[idx] > high))
            idx++;
        if(idx < preorder.size())
        {
            int key = preorder[idx];
            node = new TreeNode(key);
            node->left = helper(preorder,idx+1, low, key);
            node->right = helper(preorder,idx+1,key,high);
        }
        return node;
    }
};
