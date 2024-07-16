/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // for (int i = 0; i < nums.size(); i++)
            //     {
            //         for(int j=i+1;j<nums.size();j++)
            //         {
            //             int sum = target - nums[i];
            //             if(sum==nums[j])
            //             {
            //                 return {i,j};
            //             }
            //         }
            //     }

            // return {-1,-1};
            //
            vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                ans.push_back(m[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No solution found" << endl;
    }

    return 0;
}
