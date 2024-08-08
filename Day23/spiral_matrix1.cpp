//Given an m x n matrix, return all elements of the matrix in spiral order.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int m= mat.size();
        int n= mat[0].size();
        int total = n*m;

        int startRow = 0;
        int endRow= m-1;
        int startCol=0;
        int endCol=n-1;

        int count=0;

        while(count<total){
            //print starting row
            for(int i=startCol;i<=endCol&&count<total;i++)
            {
                ans.push_back(mat[startRow][i]);
                count++;
            }
            startRow++;
            //print end col
            for(int i=startRow;i<=endRow && count<total;i++)
            {
                ans.push_back(mat[i][endCol]);
                count++;
            }
            endCol--;
            //print end row
            for(int i=endCol;i>=startCol&&count<total;i--)
            {
                ans.push_back(mat[endRow][i]);
                count++;
            }
            endRow--;
            //print start col
            for(int i=endRow;i>=startRow&&count<total;i--)
            {
                ans.push_back(mat[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};