/*Given an m x n matrix, return all elements of the matrix in spiral order.
*/
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        // code here 
        vector<int>ans;
        int m= mat.size();
        int n= mat[0].size();
        int total = n*m;

        int startRow = 0;
        int endRow= m-1;
        int startCol=0;
        int endCol=n-1;

        int count=0;

        while(count<total){
            //print starting row
            for(int i=startCol;i<=endCol&&count<total;i++)
            {
                ans.push_back(mat[startRow][i]);
                count++;
            }
            startRow++;
            //print end col
            for(int i=startRow;i<=endRow && count<total;i++)
            {
                ans.push_back(mat[i][endCol]);
                count++;
            }
            endCol--;
            //print end row
            for(int i=endCol;i>=startCol&&count<total;i--)
            {
                ans.push_back(mat[endRow][i]);
                count++;
            }
            endRow--;
            //print start col
            for(int i=endRow;i>=startRow&&count<total;i--)
            {
                ans.push_back(mat[i][startCol]);
                count++;
            }
            startCol++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends