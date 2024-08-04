#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class neighborSum {
private:
    vector<vector<int>> grid;
    unordered_map<int, pair<int, int>> valuePositionMap;
    int n;

public:
    neighborSum(vector<vector<int>>& grid) : grid(grid), n(grid.size()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                valuePositionMap[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        if (valuePositionMap.find(value) == valuePositionMap.end()) {
            throw invalid_argument("Value not found in the grid");
        }
        int i = valuePositionMap[value].first;
        int j = valuePositionMap[value].second;
        
        int sum = 0;
        if (i > 0) sum += grid[i - 1][j];       // Top
        if (j > 0) sum += grid[i][j - 1];       // Left
        if (i < n - 1) sum += grid[i + 1][j];   // Bottom
        if (j < n - 1) sum += grid[i][j + 1];   // Right
        
        return sum;
    }
    
    int diagonalSum(int value) {
        if (valuePositionMap.find(value) == valuePositionMap.end()) {
            throw invalid_argument("Value not found in the grid");
        }
        int i = valuePositionMap[value].first;
        int j = valuePositionMap[value].second;
        
        int sum = 0;
        if (i > 0 && j > 0) sum += grid[i - 1][j - 1];       // Top-left
        if (i > 0 && j < n - 1) sum += grid[i - 1][j + 1];   // Top-right
        if (i < n - 1 && j > 0) sum += grid[i + 1][j - 1];   // Bottom-left
        if (i < n - 1 && j < n - 1) sum += grid[i + 1][j + 1]; // Bottom-right
        
        return sum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
