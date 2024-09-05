#include "header.h"

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
// 参考 LeetCode 官方方法, 但是官方没有 CPP 写法
// https://leetcode.cn/problems/word-search/solutions/2927294/liang-ge-you-hua-rang-dai-ma-ji-bai-jie-g3mmm/
// 灵茶山艾府有极致优化, 但是我做题没有使用, 还是最原始的 DFS 方法
// 搜索的话有些适合 DFS, 有些适合 BFS, 需要结合实际题目, 这道题目我自己试了一下使用 BFS 写, 有点写不太下去, 本质上应该和 DFS 差不多, 但是还是写不太下去
class Solution {
  public:
    bool exist(vector<vector<char>> &board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // if (check(board, visited, i, j, word, 0)) {
                //     return true;
                // }
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    bool check(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, string &s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int l = 0; l < 4; ++l) {
            int newi = i + dx[l], newj = j + dy[l];
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj] && check(board, visited, newi, newj, s, k + 1)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};

// @lc code=end
