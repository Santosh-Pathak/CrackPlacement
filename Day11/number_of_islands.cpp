/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.*/

#include <bits/stdc++.h>
// USING BFS
class Solution
{
public:
    void bfs(map<pair<int, int>, bool> &visited, int row, int col, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        // initial steps
        q.push({row, col});
        visited[{row, col}] = true;

        while (!q.empty())
        {
            pair<int, int> fNode = q.front();
            q.pop();
            int x = fNode.first;
            int y = fNode.second;

            // i can Move in 4 direstions
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() &&
                    !visited[{newX, newY}] && grid[newX][newY] == '1')
                {
                    q.push({newX, newY});
                    visited[{newX, newY}] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        map<pair<int, int>, bool> visited;
        int count = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            int n = grid[row].size();
            for (int col = 0; col < n; col++)
            {
                if (!visited[{row, col}] && grid[row][col] == '1')
                {
                    bfs(visited, row, col, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
// USING DFS

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        // Base case: check for boundaries and if the cell is already visited or water
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0') {
            return;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Move in the four possible directions
        dfs(grid, row - 1, col, visited); // up
        dfs(grid, row + 1, col, visited); // down
        dfs(grid, row, col - 1, visited); // left
        dfs(grid, row, col + 1, visited); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
        int count = 0;

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == '1' && !visited[row][col]) {
                    dfs(grid, row, col, visited);
                    ++count;  // Increment count for each new island
                }
            }
        }
        return count;
    }
};
