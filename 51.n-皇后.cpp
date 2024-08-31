/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// LeetCode 官方解法一
// @lc code=start
class Solution {
  private:
    vector<string> generateBoard(vector<int> &queens, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
    void backtrace(vector<vector<string>> &solutions, vector<int> &queens, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2, int n, int row) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
        }

        // 按列遍历
        for (int i = 0; i < n; i++) {
            if (columns.find(i) != columns.end()) {
                continue;
            }

            int diagonal1 = row - i;
            if (diagonals1.find(diagonal1) != diagonals1.end()) {
                continue;
            }

            int diagonal2 = row + i;
            if (diagonals2.find(diagonal2) != diagonals2.end()) {
                continue;
            }

            queens[row] = i;
            columns.insert(i);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            backtrace(solutions, queens, columns, diagonals1, diagonals2, n, row + 1);
            queens[row] = -1;
            columns.erase(i);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = unordered_set<int>();
        auto diagonals1 = unordered_set<int>();
        auto diagonals2 = unordered_set<int>();

        backtrace(solutions, queens, columns, diagonals1, diagonals2, n, 0);

        return solutions;
    }
};
// @lc code=end
