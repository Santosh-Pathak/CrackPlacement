/*You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solveUsingRecursion(vector<int>& nums, int currIndex)
    {
        if (currIndex >= nums.size() - 1) return 0;
        if (nums[currIndex] == 0) return INT_MAX;
        int ans=INT_MAX;
        for(int i=1;i<=nums[currIndex];i++)
        {
            int jump = solveUsingRecursion(nums,currIndex+i);
            if(jump!=INT_MAX)ans = min(ans , jump+1);
        }
        return ans;
    }
       int solveUsingMemo(vector<int>& nums, int currIndex, vector<int>& memo) {
        if (currIndex >= nums.size() - 1) return 0;
        if (nums[currIndex] == 0) return INT_MAX;
        if (memo[currIndex] != -1) return memo[currIndex];

        int ans = INT_MAX;
        for (int i = 1; i <= nums[currIndex]; i++) {
            int jump = solveUsingMemo(nums, currIndex + i, memo);
            if (jump != INT_MAX) {
                ans = min(ans, jump + 1);
            }
        }
        memo[currIndex] = ans;
        return ans;
    }

    int jump(vector<int>& nums) {
        // return solveUsingRecursion(nums,0);

          vector<int> memo(nums.size(), -1);
        return solveUsingMemo(nums, 0, memo);
    }
};