// You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


#include <bits/stdc++.h>
using namespace std;

class Solution
{

    bool isPossible(vector<int> arr, int n, int m, int mid)
    {
        int studentCount = 1;
        int pageSum = 0;
        // cout << "checking for mid "<< mid <<endl;

        for (int i = 0; i < n; i++)
        {
            if (pageSum + arr[i] <= mid)
            {
                pageSum += arr[i];
            }
            else
            {
                studentCount++;
                if (studentCount > m || arr[i] > mid)
                {
                    return false;
                }
                pageSum = arr[i];
            }
            if (studentCount > m)
            {
                return false;
            }
            // cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
        }
        return true;
    }

    int allocateBooks(vector<int> arr, int n, int m)
    {
        int s = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int e = sum;
        int ans = -1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (isPossible(arr, n, m, mid))
            {
                // cout<<" Mid returned TRUE" << endl;
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends