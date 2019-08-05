#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.size() <= 0)
        {
            while(!stack1.empty())
            {
                int temp = stack1.top();
                stack2.push(temp);
                stack1.pop();
                cout << "temp: " << temp << endl;
            }
        }
        assert(stack2.size() > 0);
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }
    void print()
    {
        stack<int> tmp(stack2);
        while(!tmp.empty())
        {
            cout << tmp.top() << " ";
            tmp.pop();
        }
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    Solution s;
    s.push(1);
    s.push(10);
    s.push(2);
    s.pop();
    s.print();

    s.push(5);
    s.push(6);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
  //  s.pop();
    s.print();
    return 0;
}
