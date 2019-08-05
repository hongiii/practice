#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <limits>
#include <assert.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    stack<int> stk;
    stack<int> minstk;
    void push(int value) {
        stk.push(value);
        if(minstk.size() == 0)
           minstk.push(value);
        else
        {
            int mindata = (value < minstk.top() ? value : minstk.top());
            minstk.push(mindata);
        }
    }
    void pop() {
        if(stk.size())
            stk.pop();
        if(minstk.size())
            minstk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minstk.top();
    }
};

int main()
{
    Solution s;
    s.push(12);
    s.push(7);
    cout << s.min() << " " << s.top() << endl;
    s.push(4);
    cout << s.min() << " " << s.top() << endl;
    s.pop();
    s.push(6);
    cout << s.min() << " " << s.top() << endl;
    return 0;
}
