//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int longestIncreasingSubsequenceRec(int a[], int i, int n, int prev)
    {
        if (i == n)
            return 0;

        int excludeCurrentElement = longestIncreasingSubsequence(a, i + 1, n, prev);

        int includeCurrrentElement = 0;
        if (prev < a[i])
        {
            includeCurrrentElement = 1 + longestIncreasingSubsequence(a, i + 1, n, a[i]);
        }

        return max(excludeCurrentElement, includeCurrrentElement);
    }

    // Function to find the length of the longest increasing subsequence.
    int longestIncreasingSubsequence(int a[], int i, int n, int prev_index, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;

        if (dp[i][prev_index + 1] != -1)
            return dp[i][prev_index + 1];

        int excludeCurrentElement = longestIncreasingSubsequence(a, i + 1, n, prev_index, dp);

        int includeCurrentElement = 0;
        if (prev_index == -1 || a[i] > a[prev_index])
        {
            includeCurrentElement = 1 + longestIncreasingSubsequence(a, i + 1, n, i, dp);
        }

        return dp[i][prev_index + 1] = max(excludeCurrentElement, includeCurrentElement);
    }

    int longestSubsequence(int n, int a[])
    {
        return longestIncreasingSubsequenceRec(a, 0, n, INT_MIN);

        // Creating a dp array with (n+1) size for prev_index to handle -1 case.
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return longestIncreasingSubsequence(a, 0, n, -1, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
