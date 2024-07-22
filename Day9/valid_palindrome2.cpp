// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkpalindrome(string s, int k)
    {
        s.erase(k, 1);
        int i = 0;
        int j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return (checkpalindrome(s, i) || checkpalindrome(s, j));
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};