
/*Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.*/
#include<bits/stdc++.h>

class Solution {
public:
    int solve(string s , string t ,int i , int j)
    {
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        int ans=0;
        if(s[i]==t[j])
            ans += solve(s,t,i+1,j+1);
        ans += solve(s,t,i+1,j);
        return ans; 
    }

       int solveUsingMemo(string s , string t ,int i , int j,vector<vector<int>>&dp)
    {
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
            ans += solveUsingMemo(s,t,i+1,j+1,dp);
        ans += solveUsingMemo(s,t,i+1,j,dp);
        return dp[i][j] = ans; 
    }

    int numDistinct(string s, string t) {
        // return solve(s,t,0,0);
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1,-1));
        return solveUsingMemo(s,t,0,0,dp);
    }
};