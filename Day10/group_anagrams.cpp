/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/
#include<bits/stdc+++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& nums) {
        vector<string>strs = nums;
        vector<vector<string>>ans;
        for(auto &x : strs)
        {s
            sort(x.begin(),x.end());
            // cout<<x<<" ";
        }
        map<string , vector<string>>mp;

        for(int i=0;i<nums.size();i++)
        {
                mp[strs[i]].push_back(nums[i]);
                cout<<nums[i]<<" ";
        }

        for(auto &x: mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};