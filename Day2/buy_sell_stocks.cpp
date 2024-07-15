// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - minimum;
            profit = max(profit, diff);
            minimum = min(minimum, prices[i]);
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices;

    // Example input
    prices = {7, 1, 5, 3, 6, 4};

    // Calculate the maximum profit
    int profit = solution.maxProfit(prices);

    // Output the result
    cout << "Maximum Profit: " << profit << endl;

    return 0;
}
