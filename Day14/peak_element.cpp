
/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.*/

class Solution {
public:
int peakIndex(vector<int> arr)
    {

        /*
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return i;
            }
        }
        return nums.size()-1;
        */
       
        int s=0;
        int e=arr.size()-1;
        int mid = s + (e-s)/2;
        while(s<e)
        {
            if(arr[mid]<arr[mid+1])
            {
                s= mid+1;
            }
            else
            {
                    e= mid;
            }
             mid = s + (e-s)/2;
        }
        return s;
    }
    int findPeakElement(vector<int>& nums) {
        return peakIndex(nums);
    }
};