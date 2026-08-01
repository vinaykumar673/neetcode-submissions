class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {

        int rows = heights.size();
        int cols = heights[0].size();
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        visited[row][col] = true;

        for(auto& dir : dirs) {
            int nr = row + dir[0];
            int nc = col + dir[1];

            if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                continue;
            }

            if(visited[nr][nc]) {
                continue;
            }

            if(heights[row][col] > heights[nr][nc]) {
                continue;
            }

            dfs(nr, nc, heights, visited);
        }



    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++) {
            dfs(r, 0, heights, pacific);
            dfs(r, cols - 1, heights, atlantic);
        }

        for(int c = 0; c < cols; c++) {
            dfs(0, c, heights, pacific);
            dfs(rows - 1, c, heights, atlantic);
        }

        vector<vector<int>> result;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
        
    }
};
