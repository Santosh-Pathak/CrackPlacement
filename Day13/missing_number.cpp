// /Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

#include<bits/stdc++.h>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // approach 1->Sorting and Finding
        //  sort(nums.begin(),nums.end());
        //  for(int i=0;i<nums.size();i++)
        //  {
        //      if(nums[i]==i)continue;
        //      return i;
        //  }
        //  return nums.size();
        //  Approach 2-> Usig Hasmap
        //  map<int,int>mp;
        //  for(auto x : nums)
        //  {
        //      mp[x]++;
        //  }
        //  int c=0;
        //  for(auto x : mp)
        //  {
        //      if(x.first!=c)return c;
        //      else
        //      {
        //          c++;
        //      }
        //  }
        //  return nums.size();
        //  Using Inplace algo
        int n = nums.size();

        // Iterate over the array and place each number in its correct position
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        // After rearranging, find the first index where the value is not equal
        // to the index
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                return i;
            }
        }

        // If all indices match their values, the missing number is n
        return n;
    }
};
