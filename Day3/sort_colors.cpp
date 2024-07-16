/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &arr)
    {

        //     int low=0;
        //     int mid=0;
        //     int high=arr.size()-1;
        //     while (mid <= high)
        // {
        //     if (arr[mid] == 0)
        //         swap(arr[low++], arr[mid++]);
        //     else if (arr[mid] == 1)
        //         mid++;
        //     else
        //         swap(arr[mid], arr[high--]);
        // }
        int n = arr.size();
        int zero = 0, one = 0, two = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        int i = 0;
        while (zero--)
        {
            arr[i++] = 0;
        }

        while (one--)
        {
            arr[i++] = 1;
        }

        while (two--)
        {
            arr[i++] = 2;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    solution.sortColors(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
