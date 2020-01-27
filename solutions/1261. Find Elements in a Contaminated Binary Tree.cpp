/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
    TreeNode* root;
public:
    FindElements(TreeNode* root) {
        recover(root,0);
        this->root = root;
    }
    
    bool find(int target) {
        stack<int> parents;
        parents.push(target);
        while(target){
            target = (target-1) /2;
            parents.push(target);
        }
        TreeNode* curr = root;
        while(!parents.empty()){
            int top = parents.top(); parents.pop();
            if(!curr || curr->val != top)
                return false;
            if(parents.empty())
                return true;
            if(parents.top()%2 == 0)
                curr = curr->right;
            else
                curr = curr->left;
        }
        return true;
    }
    
    void recover(TreeNode* root, int rootval){
        if(root == NULL)
            return;
        root->val = rootval;
        recover(root->left, rootval*2+1);
        recover(root->right, rootval*2+2);
    }
};
​
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
