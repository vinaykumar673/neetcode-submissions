class Solution {

private:
    queue<pair<int, int>> q;
    int ROWS, COLS;

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        ROWS = grid.size();
        COLS = grid[0].size();
        vector<vector<bool>> visit(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i, j});
                    visit[i][j] = true;
                }
            }
        }

        int dist = 0;
        while(!q.empty())
        {
            int len = q.size();

            for(int i = 0; i < len; i++)
            {
                pair<int, int> p = q.front();
                q.pop();
                int r = p.first, c = p.second;
                grid[r][c] = dist;
                addRoom(r + 1, c, visit, grid);
                addRoom(r - 1, c, visit, grid);
                addRoom(r, c + 1, visit, grid);
                addRoom(r, c - 1, visit, grid);
            }
            dist++;
        }
    }

    void addRoom(int r, int c, vector<vector<bool>>& visit, vector<vector<int>>& grid)
    {
        if(r < 0 or r == ROWS or c < 0 or c == COLS or visit[r][c] == true or grid[r][c] == -1)
        {
            return;
        }

        visit[r][c] = true;
        q.push({r, c});
    }
};
