/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.*/

#include<bits/stdc++.h>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false; 
        return ((n&(n-1))==0);

        // Approach 2 -  by Counting  number set Bits
        // int count=0;
        // while(n!=0)
        // {
        //     int a  = n & 1;
        //     if(a)count++;
        //     n = n>>1;
        // }
        // return count==1;
    }
};