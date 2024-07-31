//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
         string common="";
        for(int i=0;i<strs[0].size();i++)
        {
           char ch =strs[0][i];
           bool match = true;
           //for comparing remaining string 
           for(int j=1;j<strs.size();j++)
           {
               if(strs[j].size()< i|| ch !=strs[j][i])
               {    match =false;
                    break;
               }
           }
           if(match==false)
           break;
           else
           common.push_back(ch);
        }
        if(common == "")return "-1";
        return common;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends