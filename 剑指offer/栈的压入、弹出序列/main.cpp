#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int len = pushV.size();

        if(len == 0) return false;
        if(len == 1) return pushV[0] == popV[0];

        int cnt = 0, i = 0;
        while(cnt <= len)
        {
            if(stk.size() == 0 || stk.top() != popV[cnt])
            {
                if(i > len)
                    break;
                stk.push(pushV[i]);
                ++i;
            }
            if(stk.top() == popV[cnt])
            {
                stk.pop();
                cnt++;
            }
            if(cnt > len)
                break;
        }
        return stk.size() == 0;
    }
};

int main()
{
    vector<int> vec1{1,2,3,4,5};
    vector<int> vec2{4,5,3,2,1};
    vector<int> vec3{4,3,5,1,2};
    Solution s;
    cout << s.IsPopOrder(vec1, vec2) << endl;
    cout << s.IsPopOrder(vec1, vec3) << endl;
    return 0;
}
