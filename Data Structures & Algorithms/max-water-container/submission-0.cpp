class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = (int)heights.size() - 1;
        int max_area = 0;

        while(l < r) {
            int curr_height = min(heights[l], heights[r]);
            int curr_area = curr_height * (r - l);
            max_area = max(max_area, curr_area);

            if(heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return max_area;
        
    }
};
