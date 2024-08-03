#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsForPalindrome(const vector<int>& arr) {
    int flips = 0;
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        if (arr[l] != arr[r]) {
            flips++;
        }
        l++;
        r--;
    }
    return flips;
}
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        for (const auto& row : grid) {
            rowFlips += minFlipsForPalindrome(row);
        }

        int colFlips = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> col(m);
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            colFlips += minFlipsForPalindrome(col);
        }

        return min(rowFlips, colFlips);
    }
};