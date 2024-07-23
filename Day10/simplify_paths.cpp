/*
Given an absolute path for a Unix-style file system, which begins with a slash '/', transform this path into its simplified canonical path.
In Unix-style file system context, a single period '.' signifies the current directory, a double period ".." denotes moving up one directory level, and multiple slashes such as "//" are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous rules (like "...") as valid names for files or directories.
The simplified canonical path should adhere to the following rules:
It must start with a single slash '/'.
Directories within the path should be separated by only one slash '/'.
It should not end with a slash '/', unless it's the root directory.
It should exclude any single or double periods used to denote current or parent directories.
Return the new path.
 */
#include<bits/stdc+++.h>
class Solution {
public:
void buildAns(stack<string>&st,string &ans)
{
    if(st.empty())
    {
        return;
    }
    string minpath = st.top(); 
    st.pop();
    buildAns(st,ans);
    ans+=minpath;
}
    string simplifyPath(string path) {
        stack<string>st;
        int i=0;
        while(i < path.size())
        {
            int start =i;
            int end = i+1;

            while(end < path.size() && path[end] != '/')
            {
                ++end;
            }
            string minpath = path.substr(start ,end-start);
            i =end;
            if(minpath == "/" || minpath=="/.")
            {
                continue;
            }

            if(minpath != "/..")
            {
                st.push(minpath);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }
        string ans =st.empty() ?"/" : "";
        buildAns(st,ans);
        return ans;
    }
};