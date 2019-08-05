#include <iostream>
#include <queue>
using namespace std;
//用两个队列来回交换
class Solution
{
public:
  void push(int node) {
        queue1.push(node);
    }

    int pop() {
        int res = 0;
        while(queue1.size() >= 1)
        {
            if(queue1.size() == 1)
            {
                res = queue1.front();
                queue1.pop();
                return res;
            }
            else
            {
                int tmp = queue1.front();
                queue2.push(tmp);
                queue1.pop();
                cout << "tmp: " << tmp << endl;
            }
        }
        while(queue2.size() >= 1)
        {
            if(queue2.size() == 1)
            {
                res = queue2.front();
                queue2.pop();
                return res;
            }
            else
            {
                int tmp = queue2.front();
                queue1.push(tmp);
                queue2.pop();
                cout << "tmp: " << tmp << endl;
            }
        }
        return res;
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};

int main()
{
    Solution s;
    s.push(2);
    s.push(3);
    s.push(5);
    cout << s.pop() << endl;
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
