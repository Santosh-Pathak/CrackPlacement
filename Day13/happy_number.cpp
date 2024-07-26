 // Write an algorithm to determine if a number n is happy
// A happy number is a number defined by the following process:
// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

#include<bits/stdc++.h>
#include <set>

class HappyNumberChecker {
public:
    int findNewNumber(int n) {
        int ans = 0;
        while (n) {
            int x = n % 10;
            ans += x * x;
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        if (n <= 0) return false; // input validation

        std::set<int> s;
        s.insert(n);
        while (n != 1) {
            int ans = findNewNumber(n);
            if (ans == 1) return true;
            if (s.find(ans) != s.end()) return false;
            s.insert(ans);
            n = ans;
        }
        return true;
    }
};