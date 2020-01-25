class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = INT_MIN, curr_sum = 0;
        for(int i = 0; i <nums.size(); i++){
            curr_sum = curr_sum + nums[i];
            if(curr_sum > curr_max)
                curr_max = curr_sum;
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return curr_max;
    }
};
