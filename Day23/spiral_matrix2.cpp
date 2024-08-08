//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int total = n * n;
        int startRow = 0, endRow = n - 1, startCol = 0, endCol = n - 1;
        int count = 1; // Start from 1, not 0
        vector<vector<int>> result(n, vector<int>(n, 0)); // Initialize result matrix
        
        while (count <= total) {
            // Traverse right
            for (int i = startCol; i <= endCol; i++) {
                result[startRow][i] = count;
                count++;
            }
            startRow++;

            // Traverse down
            for (int i = startRow; i <= endRow; i++) {
                result[i][endCol] = count;
                count++;
            }
            endCol--;

            // Traverse left
            for (int i = endCol; i >= startCol; i--) {
                result[endRow][i] = count;
                count++;
            }
            endRow--;

            // Traverse up
            for (int i = endRow; i >= startRow; i--) {
                result[i][startCol] = count;
                count++;
            }
            startCol++;
        }
        return result;
    }
};