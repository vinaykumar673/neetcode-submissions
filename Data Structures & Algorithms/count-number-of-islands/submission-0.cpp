class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col) {

        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        if(row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        for(auto& dir : directions) {
            dfs(grid, row + dir.first, col + dir.second);
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int num_of_islands = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '1') {
                    num_of_islands++;
                    dfs(grid, r, c);
                }
            }
        }

        return num_of_islands;
        
    }
};
