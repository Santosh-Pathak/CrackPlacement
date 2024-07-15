/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // APPROACH 1st
        // sort(nums.begin(),nums.end());
        // for(int i=0; i<nums.size()-1; i++) {
        //     if(nums[i] == nums[i+1]) {
        //         return nums[i];
        //     }
        // }
        // return -1;

        // APPROACH 2nd
        while(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

int main() {
    Solution solution;
    vector<int> nums;

    // Example input
    nums = {3, 1, 3, 4, 2};

    // Find the duplicate number
    int duplicate = solution.findDuplicate(nums);

    // Output the result
    cout << "Duplicate Number: " << duplicate << endl;

    return 0;
}
