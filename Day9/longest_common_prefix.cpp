/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".*/

#include <bits/stdc++.h>
using namespace std;

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
        return common;
    }
};