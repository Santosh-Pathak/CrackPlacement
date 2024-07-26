/*
Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#include <algorithm>
#include <vector>
#include <cstdlib>  // For abs function

class Solution {
public:
    int findPair(int n, int x, std::vector<int> &arr) {
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; ++i) {
            int ele1 = arr[i] + x;
            int ele2 = arr[i] - x;
            // Binary search for ele1
            int s = i + 1, e = n - 1;
            while (s <= e) {
                int mid = (s + e) / 2;
                if (arr[mid] == ele1 || arr[mid] == ele2) {
                    return 1;
                } else if (arr[mid] > ele1) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends