// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
#include<iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    v.push_back({i, j});
                }
            }
        }

        for (auto& x : v) {
            int i = x.first;
            int j = x.second;
            for(int k = 0;k<m;k++)
            {
                matrix[i][k] = 0;
            }
            
            for(int k = 0;k<n;k++)
            {
                matrix[k][j] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution sol;
    sol.setZeroes(matrix);

    // Print the modified matrix
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
