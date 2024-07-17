/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int solveUsingRecursion(vector<int> &prices,int i,bool buy)
    // {
    //     if(i>= prices.size()) return 0;
    //     int profit = 0;
    //     if(buy)
    //     {
    //         int profit1 = -prices[i] + solveUsingRecursion(prices,i+1,false);
    //         int profit2 = 0 + solveUsingRecursion(prices,i+1,true);
    //         profit = max(profit1,profit2);
    //     }
    //     else
    //     {
    //         int profit1 = prices[i] + solveUsingRecursion(prices,i+1,true);
    //         int profit2 = 0 + solveUsingRecursion(prices,i+1,false);
    //         profit = max(profit1,profit2);
    //     }
    //     return profit;
    // }
    int solveUsingMemo(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy)
        {
            int profit1 = -prices[i] + solveUsingMemo(prices, i + 1, false, dp);
            int profit2 = 0 + solveUsingMemo(prices, i + 1, true, dp);
            profit = max(profit1, profit2);
        }
        else
        {
            int profit1 = prices[i] + solveUsingMemo(prices, i + 1, true, dp);
            int profit2 = 0 + solveUsingMemo(prices, i + 1, false, dp);
            profit = max(profit1, profit2);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        // Approach NO-1
        //  int buy = prices[0];
        //  int profit = 0;
        //  for (int i = 1; i < prices.size(); i++)
        //  {
        //      if (prices[i] < prices[i - 1]) // price drop
        //      {
        //          profit += prices[i - 1] - buy;
        //          buy = prices[i];
        //      }
        //  }
        //  profit += prices[prices.size() - 1] - buy;
        //  return profit;

        // Approach 2 -Using Recursion + DP
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        return solveUsingMemo(prices, 0, true, dp);
    }
};