/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
A subarray is a contiguous part of an array.*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int subarraysDivByK(vector<int> &nums, int K)
    {

        int n = nums.size();

        // Brite Force Method 0(n^3)
        // int c =0;
        // int sum=0;
        // for(int i=0;i<n;i++)

        //     for(int j=i;j<n;j++)
        //     {
        //         sum=0;
        //         for(int k =i;k<=j;k++)
        //             {
        //                 sum+=nums[k];
        //             }
        //         if(sum%K==0)c++;
        //     }

        // return c;
        // Prefix sum array Method (0(n^2))
        // int n = nums.size();

        // std::vector<int> sumArray(n, 0); // Initialize sumArray with size n and all elements set to 0

        // int val = 0;
        // int c = 0;
        // for (int i = 0; i < n; i++) {
        //     val += nums[i];
        //     sumArray[i] = val;
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         int sum = (i == 0) ? sumArray[j] : (sumArray[j] - sumArray[i - 1]);
        //         if (sum % K == 0) {
        //             c++;
        //         }
        //     }
        // }

        // return c;

        unordered_map<int, int> mp;

        int sum = 0;
        mp[0] = 1;
        int result = 0;

        for (int i = 0; i < n; i++)
        {

            sum += nums[i];

            int rem = sum % K;
            if (rem < 0)
            {
                rem += K;
            }
            if (mp.find(rem) != mp.end())
            {
                result += mp[rem];
            }
            mp[rem]++;
        }
        return result;
    }
};
