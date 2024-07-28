/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/
#include <bits/stdc++.h>

class Solution
{
public:
    int findPivot(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return -1; // Handle empty array

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return -1; // Return -1 if no pivot found, indicating the array is not rotated
    }

    int bs(vector<int> &arr, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            int element = arr[mid];

            if (element == target)
            {
                return mid; // Element found, return index
            }

            if (target < element)
            {
                // Search in left half
                end = mid - 1;
            }
            else
            {
                // Search in right half
                start = mid + 1;
            }
        }

        // Element not found
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = findPivot(nums);

        // If the array is not rotated, pivot will be -1
        if (pivot == -1)
        {
            return bs(nums, target, 0, n - 1);
        }

        // If target is in the left sorted part
        if (target >= nums[0] && target <= nums[pivot])
        {
            return bs(nums, target, 0, pivot);
        }

        // If target is in the right sorted part
        if (pivot + 1 < n && target >= nums[pivot + 1] && target <= nums[n - 1])
        {
            return bs(nums, target, pivot + 1, n - 1);
        }

        return -1; // Element not found
    }
};
