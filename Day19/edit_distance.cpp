//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int m,n;

   vector<vector<int>> dp;
    int solveUsingMemo(string s1, string s2, int i, int j) {
        // Base cases
        if (i == s1.size()) {
            return n - j;
        }
        if (j == s2.size()) {
            return m - i;
        }

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            // Characters match, no operation needed
            dp[i][j] = solveUsingMemo(s1, s2, i + 1, j + 1);
        } else {
            // Calculate the minimum of inserting, deleting, and replacing a character
            int insertC = 1 + solveUsingMemo(s1, s2, i, j + 1);
            int deleteC = 1 + solveUsingMemo(s1, s2, i + 1, j);
            int replaceC = 1 + solveUsingMemo(s1, s2, i + 1, j + 1);
            dp[i][j] = min({insertC, deleteC, replaceC});
        }

        return dp[i][j];
    }


    int editDistance(string word1, string word2) {
        // Code here
        
         m=word1.size() ;
        n=word2.size() ;
        // return solve(word1, word2, 0, 0);
         dp = vector<vector<int>>(m, vector<int>(n, -1));
        return solveUsingMemo(word1, word2, 0, 0);

    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends