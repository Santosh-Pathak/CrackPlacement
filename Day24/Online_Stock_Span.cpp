

#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    StockSpanner() {}

    std::stack<std::pair<int, int>> st;

    int next(int price)
    {
        int span = 1;

        // Pop elements from the stack while the current price is greater than
        // or equal to the stack's top price.
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its span onto the stack.
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
