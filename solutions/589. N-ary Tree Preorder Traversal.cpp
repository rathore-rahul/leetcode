/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
​
    Node() {}
​
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node * t = st.top();
            st.pop();
            if(t == NULL)
                break;
            ans.push_back(t->val);
            for(int i = t->children.size()-1 ;i >=0 ; i--){
                st.push(t->children[i]);
            }
        }
        return ans;
    }
};
