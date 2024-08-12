//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class twoStacks {
public:
    int n = 200;
    std::vector<int> arr;
    int i;
    int j;

    // Constructor to initialize the data structures and variables.
    twoStacks() : arr(n, -1), i(0), j(n-1) {}

    // Function to push an integer into stack1.
    void push1(int x) {
        if (i <= j) {
            arr[i] = x;
            i++;
        } else {
            std::cout << "Stack1 Overflow" << std::endl;
        }
    }

    // Function to push an integer into stack2.
    void push2(int x) {
        if (i <= j) {
            arr[j] = x;
            j--;
        } else {
            std::cout << "Stack2 Overflow" << std::endl;
        }
    }

    // Function to remove an element from top of stack1.
    int pop1() {
        if (i > 0) {
            i--;
            int x = arr[i];
            arr[i] = -1;  // Optional: Reset the value
            return x;
        } else {
            return -1;  // Stack1 Underflow
        }
    }

    // Function to remove an element from top of stack2.
    int pop2() {
        if (j < n-1) {
            j++;
            int x = arr[j];
            arr[j] = -1;  // Optional: Reset the value
            return x;
        } else {
            return -1;  // Stack2 Underflow
        }
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends