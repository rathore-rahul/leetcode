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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> counter;
        int max_count = 0;
        helper(root, counter, max_count);
        vector<int> result;
        for(map<int,int>::iterator it = counter.begin(); it != counter.end(); it++){
            if(it->second == max_count)
                result.push_back(it->first);
        }
        return result;
    }
    
    int helper(TreeNode* root, map<int,int> & counter, int & max_count){
        if(root == NULL)
            return 0;
        int l = helper(root->left,counter,max_count);
        int r = helper(root->right,counter,max_count);
        int subtree_sum = l + r + root->val;
        counter[subtree_sum] += 1;
        if(counter[subtree_sum] > max_count){
            max_count = counter[subtree_sum];
        }
        return subtree_sum;
    }
};
