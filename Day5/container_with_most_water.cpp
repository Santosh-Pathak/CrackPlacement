/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size() - 1;
        int maxArea = INT_MIN;

        while(s<e)
        {
            int left = height[s];
            int right = height[e];

            int minHeight = min(left ,right);
            int area = minHeight * (e-s);
            maxArea = max(area,maxArea);
            if(left < right)s++;
            else e--;
        }
        return maxArea;
    }
};