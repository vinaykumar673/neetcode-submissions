class Solution {
public:

    bool explore(vector<vector<char>>& board, string word, int r, int c, int ind) {

        if(board[r][c] != word[ind]) {
            return false;
        }

        if(ind == word.size() - 1) {
            return true;
        }

        char saved = board[r][c];
        board[r][c] = '#';

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int d = 0; d < 4; d++) {
                int nr = r + dirs[d][0];
                int nc = c + dirs[d][1];

                if(nr < 0 || nr >= board.size() || 
                   nc < 0 || nc >= board[nr].size()) {
                    continue;
                   }

                    if(explore(board, word, nr, nc, ind + 1)) {
                        board[r][c] = saved;
                        return true;
                    }
        }

        board[r][c] = saved;
        return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[r].size(); c++) {
                    if(explore(board, word, r, c, 0)) {
                        return true;
                    }
            }
        }

        return false;

    }
};
