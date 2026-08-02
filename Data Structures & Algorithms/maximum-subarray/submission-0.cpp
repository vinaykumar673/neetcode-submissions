class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int curr_sum = nums[0];
        int res = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            curr_sum = max(curr_sum + nums[i], nums[i]);
            res = max(res, curr_sum);
        }

        return res;
        
    }
};
