/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.*/
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums, int currIndex)
    {
        if(currIndex==nums.size()-1)return true;
        if(currIndex >= nums.size() || nums[currIndex]==0)return false;
        bool ans = false;
        for(int i=1;i<=nums[currIndex];i++)
        {
              if(solveUsingRecursion(nums,currIndex+i))return true;
        }
        return false;
    }
        bool solveUsingMemo(vector<int>& nums, int currIndex,vector<int>& dp)
    {
        if (currIndex == nums.size() - 1) return true;
        if (currIndex >= nums.size() || nums[currIndex] == 0) return false;
        if (dp[currIndex] != -1) return dp[currIndex];
        
        for (int i = 1; i <= nums[currIndex]; i++) {
            if (solveUsingMemo(nums, currIndex + i, dp)) {
                dp[currIndex] = 1;
                return true;
            }
        }
        dp[currIndex] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        if(nums[0]==0 &&nums.size()!=1)return false;
        // return solveUsingRecursion(nums,0);

        vector<int>dp(nums.size()+1,-1);
        return solveUsingMemo(nums,0,dp);

    }
};
ver Code Ends