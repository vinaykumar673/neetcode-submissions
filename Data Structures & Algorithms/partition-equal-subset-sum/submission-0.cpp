class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int total_sum = 0;
        for(auto& num : nums) {
            total_sum += num;
        }

        if(total_sum % 2 != 0 ) {
            return false;
        } 

        int target = total_sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(auto& num : nums) {
            for(int w = target; w >= num; w--) {
                dp[w] = dp[w] || dp[w - num];
            }
        }

        return dp[target];
        
    }
};
