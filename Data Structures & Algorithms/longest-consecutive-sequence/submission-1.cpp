class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> setNums(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int longest = 1;
            int currNum = nums[i];
            while(setNums.count(currNum + 1)) {
                longest++;
                currNum++;
            }
            res = max(res, longest);
        }

        return res;
    }
};
