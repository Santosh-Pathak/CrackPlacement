
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        for (int i = 0; i <= n - m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s1[i + j] != s2[j])
                {
                    break;
                }

                if (j == m - 1)
                    return i;
            }
        }

        return -1;
    }
};