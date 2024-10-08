// Given two binary strings a and b, return their sum as a binary string.
#include <bits/stdc++.h>
class Solution
{
public:
    string addBinary(string a, string b)
    {
        const int m = a.size();
        const int n = b.size();
        bool flag = false;
        string filler = "";
        bool carry = false;
        if (m >= n)
        {
            flag = true;
        }
        for (int i = 0; i < abs(m - n); ++i)
        {
            filler += "0";
        }
        string ans = "";
        if (flag)
        {
            b = filler + b;
        }
        else
        {
            a = filler + a;
        }
        const int limit = a.size();
        for (int i = limit - 1; i >= 0; --i)
        {
            if (a[i] == b[i] && a[i] == '1')
            {
                if (carry)
                {
                    ans += "1";
                    carry = true;
                }
                else
                {
                    ans += "0";
                    carry = true;
                }
            }
            else if (a[i] == b[i] && a[i] == '0')
            {
                if (carry)
                {
                    ans += "1";
                    carry = false;
                }
                else
                {
                    ans += "0";
                    carry = false;
                }
            }
            else
            {
                if (carry)
                {
                    ans += "0";
                    carry = true;
                }
                else
                {
                    ans += "1";
                    carry = false;
                }
            }
        }
        if (carry)
        {
            ans += "1";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};