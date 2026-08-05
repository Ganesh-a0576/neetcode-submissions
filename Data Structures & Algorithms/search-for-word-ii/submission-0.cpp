class Solution {
private:
    bool dfs(int i, int j, int idx, vector<vector<char>>& board, string &word) {
        if (idx == word.size())
            return true;

        int n = board.size(), m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return false;

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';   // mark visited

        bool found =
            dfs(i + 1, j, idx + 1, board, word) ||
            dfs(i - 1, j, idx + 1, board, word) ||
            dfs(i, j + 1, idx + 1, board, word) ||
            dfs(i, j - 1, idx + 1, board, word);

        board[i][j] = temp;  // restore

        return found;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        int n = board.size(), m = board[0].size();

        for (string &word : words) {
            bool found = false;

            for (int i = 0; i < n && !found; i++) {
                for (int j = 0; j < m && !found; j++) {
                    if (dfs(i, j, 0, board, word)) {
                        ans.push_back(word);
                        found = true;
                    }
                }
            }
        }

        return ans;
    }
};