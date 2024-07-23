
/*Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces betwee two words. The returned string should only have a single space separating the words. Do not include any extra spaces.*/
#include<bits/stdc+++.h>

class Solution {
public:
    string reverseWords(string s) {
        // Remove leading and trailing spaces
        int start = 0, end = s.size() - 1;
        while (start <= end && s[start] == ' ') start++;
        while (end >= start && s[end] == ' ') end--;
        
        if (start > end) return "";

        // Reduce multiple spaces to a single space
        string temp;
        for (int i = start; i <= end; ++i) {
            if (s[i] != ' ' || (i > start && s[i] == ' ' && s[i - 1] != ' ')) {
                temp += s[i];
            }
        }

        // Reverse the entire string
        int i = 0, j = temp.size() - 1;
        while (i < j) {
            swap(temp[i], temp[j]);
            i++;
            j--;
        }

        // Reverse each word in the reversed string
        int n = temp.size();
        i = 0;
        while (i < n) {
            int j = i;
            while (j < n && temp[j] != ' ') j++;
            int k = j - 1;
            while (i < k) {
                swap(temp[i], temp[k]);
                i++;
                k--;
            }
            i = j + 1;
        }

        return temp;
    }
};
