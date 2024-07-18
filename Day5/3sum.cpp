/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        // APPROACH NO -1 0(n3)
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // Iterate through all possible triplets
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Check if the sum of the triplet is zero and if it's unique
                    if (nums[i] + nums[j] + nums[k] == 0 && isUnique(result, nums[i], nums[j], nums[k])) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        //APPROACH NO-2 0(nlogn)
        int a=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {  
            int j=i+1;
           int k=nums.size()-1;
           while(j<k)
           {
               if(nums[i]+nums[j]+nums[k]==0)
             {
                 ans.push_back({nums[i],nums[j],nums[k]});
                 while(j<k && nums[j] == nums[j+1]) j++;
                 while(j<k && nums[k] == nums[k-1]) k--;
                 j++;
                 k--;
                 
             }
               else if(nums[i]+nums[j]+nums[k]>0)
               k--;
               else
               j++;   
           }
           
                 while(i+1<nums.size() && nums[i+1] == nums[i])i++;
        }
        return ans;
    }
};


