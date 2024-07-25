// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include<bits/stdc++.h>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose the Matrix
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse the rows of matrix
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin() , matrix[i].end());
        }


    }
};