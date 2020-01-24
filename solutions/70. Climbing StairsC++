class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int prev = 2, prev_prev = 1;
        for(int i = 3;  i<= n ; i++){
            int curr = prev + prev_prev;
            prev_prev = prev;
            prev = curr;
        }
        return prev;
    }
};
