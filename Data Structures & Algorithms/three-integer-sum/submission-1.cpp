class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < (int)nums.size() - 1; i++) {
            int target = -1 * nums[i];
            int l = i + 1;
            int r = (int)nums.size() - 1;
            while(l < r) {
                int curr_sum = nums[l] + nums[r];
                if(curr_sum == target) {
                    vector<int> curr_triplet = {nums[i], nums[l], nums[r]};
                    sort(curr_triplet.begin(), curr_triplet.end());
                    if(count(res.begin(), res.end(), curr_triplet) == 0) {
                        res.push_back(curr_triplet);
                    }
                    l++;
                    r--;
                }
                else if(curr_sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }

        return res;
        
    }
};
