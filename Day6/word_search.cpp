// Given an m x n grid of characters board and a string word, return true if word exists in the grid
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once. 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m = 0, n = 0;
    bool BFS(vector<vector<char>>& board, string word, int i, int j,
             int currIndex) {

        if (currIndex == word.size())
            return true;
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[currIndex])
            return false;

        char c = board[i][j];
        board[i][j] = '@';

        bool ans = (BFS(board, word, i - 1, j, currIndex + 1)||
                    BFS(board, word, i, j - 1, currIndex + 1)||
                    BFS(board, word, i + 1, j, currIndex + 1)||
                    BFS(board, word, i, j + 1, currIndex + 1));

        board[i][j] = c;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && BFS(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};