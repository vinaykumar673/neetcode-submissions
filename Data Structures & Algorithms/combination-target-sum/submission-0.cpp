class Solution {
public:

    void backtrack(vector<int>& nums, int target, vector<vector<int>>& result, vector<int> subset, int start, int curr_sum) {

        if(curr_sum == target) {
            result.push_back(subset);
            return;
        }

        if(curr_sum > target) {
            return;
        }

        for(int i = start; i < nums.size(); i++) {

            curr_sum += nums[i];
            subset.push_back(nums[i]);
            backtrack(nums, target, result, subset, i, curr_sum);
            curr_sum -= nums[i];
            subset.pop_back();
        }


    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        backtrack(nums, target, result, {}, 0, 0);
        return result;

    }
};
