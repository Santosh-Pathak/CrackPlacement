/*You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.
Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. Since the answer can be a huge number return it modulo 109 + 7.
 */

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int MOD = 1e9 + 7;
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> rangeSum;
        rangeSum.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                rangeSum.push_back(sum);
            }
        }
        sort(rangeSum.begin(), rangeSum.end());
        int sum = 0;
        for (int i = left; i <= right && i < rangeSum.size(); i++)
        {
            sum = (sum + rangeSum[i]) % MOD;
        }
        return sum;
    }
};