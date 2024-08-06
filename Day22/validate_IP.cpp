//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isValid(string str) {
        string part = "";
        int countPart = 0;
        
        for (int i = 0; i <= str.size(); i++) {
            if (i == str.size() || str[i] == '.') {
                if (part.empty() || part.size() > 3) return false;
                
                // Check if the part contains only digits
                for (char c : part) {
                    if (!isdigit(c)) return false;
                }
                
                // Convert part to integer and check range
                int num = stoi(part);
                if (num < 0 || num > 255) return false;
                
                // Check for leading zeros
                if (part.size() > 1 && part[0] == '0') return false;
                
                countPart++;
                part = "";
            } else {
                part += str[i];
            }
        }
        
        // Valid IP should have exactly 4 parts
        return countPart == 4;
    }
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends