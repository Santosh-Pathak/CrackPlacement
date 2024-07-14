//Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Note that you must do this in-place without making a copy of the array.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[s]);
                s++;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    
    Solution sol;
    sol.moveZeroes(nums);
    
    // Print the modified array
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}


