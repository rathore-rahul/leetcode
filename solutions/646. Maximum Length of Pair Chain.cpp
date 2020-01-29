bool compare(vector<int>& first, vector<int>& second){
        return first[1] < second[1];
    }
​
class Solution {
public:
    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int ans = 0, curr = -1e9;
        for(vector<int> x : pairs){
            if(x[0] > curr){
                ans++;
                curr = x[1];
            }
        }
        return ans;
    }
};
