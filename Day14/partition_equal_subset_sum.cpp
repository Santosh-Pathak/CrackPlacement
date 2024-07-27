/*Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int arr[], int sum, int i, int n, vector<vector<int>>& dp) {
        if (sum == 0) return 1; // Found a subset with the required sum
        if (i >= n || sum < 0) return 0; // Out of bounds or sum becomes negative

        if (dp[i][sum] != -1) return dp[i][sum];

        int include = solve(arr, sum - arr[i], i + 1, n, dp);
        int exclude = solve(arr, sum, i + 1, n, dp);

        return dp[i][sum] = include || exclude;
    }

    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }
        
        if (sum % 2 != 0) return 0; // If the total sum is odd, can't be divided equally
        
        sum /= 2;
        vector<vector<int>> dp(N, vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, N, dp);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends