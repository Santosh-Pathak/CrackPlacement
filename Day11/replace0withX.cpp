/*Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <vector>

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<char>> &mat, int x, int y, int m, int n)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] != 'O')
            return false;

        mat[x][y] = '#'; // Marking this 'O' as visited

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            dfs(mat, newX, newY, m, n);
        }

        return true;
    }

    std::vector<std::vector<char>> fill(int m, int n, std::vector<std::vector<char>> mat)
    {
        // Check the boundary for 'O' and mark them and connected 'O's
        for (int i = 0; i < m; i++)
        {
            if (mat[i][0] == 'O')
                dfs(mat, i, 0, m, n);
            if (mat[i][n - 1] == 'O')
                dfs(mat, i, n - 1, m, n);
        }

        for (int j = 0; j < n; j++)
        {
            if (mat[0][j] == 'O')
                dfs(mat, 0, j, m, n);
            if (mat[m - 1][j] == 'O')
                dfs(mat, m - 1, j, m, n);
        }

        // Flip all 'O' to 'X' and '#' back to 'O'
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                else if (mat[i][j] == '#')
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends