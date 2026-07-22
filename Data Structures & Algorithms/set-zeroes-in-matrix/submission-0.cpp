class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int ROWS = matrix.size(), COLS = matrix[0].size();
        vector<bool> zeroRows(ROWS, false);
        vector<bool> zeroCols(COLS, false);

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(matrix[r][c] == 0) {
                    zeroRows[r] = true;
                    zeroCols[c] = true;
                }
            }
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(zeroRows[r] || zeroCols[c]) {
                    matrix[r][c] = 0;
                }
            }
        }
        
    }
};
