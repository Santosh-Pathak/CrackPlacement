/*Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.*/


#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count =0;
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];
            if(mp.find(sum-k)!= mp.end())
            {
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        // code here
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count =0;
        for(int i=0;i<N;i++)
        {
            sum+=Arr[i];
            if(mp.find(sum-k)!= mp.end())
            {
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};
