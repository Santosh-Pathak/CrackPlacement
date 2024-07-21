/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string expr)
    {
        stack<char> temp;
        for (int i = 0; i < expr.length(); i++)
        {
            if (temp.empty())
            {
                // If the stack is empty
                // just push the current bracket
                temp.push(expr[i]);
            }
            else if ((temp.top() == '(' && expr[i] == ')') || (temp.top() == '{' && expr[i] == '}') || (temp.top() == '[' && expr[i] == ']'))
            {

                // If we found any complete pair of bracket
                // then pop
                temp.pop();
            }
            else
            {
                temp.push(expr[i]);
            }
        }
        if (temp.empty())
        {

            // If stack is empty return true
            return true;
        }
        return false;
    }
};