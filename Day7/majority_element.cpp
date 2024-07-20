/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // return nums[n/2];

        // Approach 2
        // int n = nums.size();
        // unordered_map<int, int> m;

        // for (int i = 0; i < n; i++) {
        //     m[nums[i]]++;
        // }
        // n = n / 2;
        // for (auto x : m) {
        //     if (x.second > n) {
        //         return x.first;
        //     }
        // }
        // return 0;

        // ..Approach 3
        int c = 0, vote = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (vote == 0)
                c = nums[i];
            if (c == nums[i])
                vote++;
            else
                vote--;
        }
        return c;
    }
};
