/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;

        // Map each value in nums2 to its index
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        // Iterate over each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];
            int index = mp[num]; // Get the index of nums1[i] in nums2
            int nextGreater = -1; // Default to -1 if no greater element is found

            // Look for the next greater element in nums2
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[j] > num) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};
