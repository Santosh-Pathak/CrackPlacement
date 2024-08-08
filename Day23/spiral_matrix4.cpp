/*You are given two integers m and n, which represent the dimensions of a matrix.
You are also given the head of a linked list of integers.
Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.
Return the generated matrix.*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int startRow = 0, endRow = m - 1, startCol = 0, endCol = n - 1;
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Initialize result matrix

        while (head) {
            // Traverse right
            for (int i = startCol; i <= endCol && head != nullptr; i++) {
                ans[startRow][i] = head->val;
                head = head->next;
            }
            startRow++;

            // Traverse down
            for (int i = startRow; i <= endRow && head != nullptr; i++) {
                ans[i][endCol] = head->val;
                head = head->next;
            }
            endCol--;

            // Traverse left
            for (int i = endCol; i >= startCol && head != nullptr; i--) {
                ans[endRow][i] = head->val;
                head = head->next;
            }
            endRow--;

            // Traverse up
            for (int i = endRow; i >= startRow && head != nullptr; i--) {
                ans[i][startCol] = head->val;
                head = head->next;
            }
            startCol++;
        }
        return ans;
    }
};
