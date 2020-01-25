class Solution {
public:
    int rob(vector<int>& nums) {
        int fn_1 = 0, fn_2 = 0;
        for(int i = 0; i < nums.size(); i++){
            int curr = max(fn_1, fn_2 + nums[i]);
            fn_2 = fn_1;
            fn_1 = curr;
        }
        return fn_1;
    }
};
