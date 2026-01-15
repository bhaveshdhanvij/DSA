class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'X')
            return;

        board[i][j] = '.';  
        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }

    int countBattleships(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    count++;
                    dfs(i, j, board);
                }
            }
        }
        return count;
    }
};
