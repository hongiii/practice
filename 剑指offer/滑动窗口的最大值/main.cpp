#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;

        unsigned int len = num.size();
        if(len <= 0) return res;
        deque<int> dq;
        for(unsigned int i = 0; i < len; i++)
        {
            while(dq.size() && num[i] >= num[dq.back()]) dq.pop_back();
            while(dq.size() && i-dq.front()+1 > size) dq.pop_front();
            dq.push_back(i);
            if(size && i+1 >= size)
                res.push_back(num[dq.front()]);
        }
        return res;
    }

};

int main()
{
    vector<int> vec = {2,3,4,2,6,2,5,1};
    int size = 3;
    Solution s;
    vector<int> res = s.maxInWindows(vec, size);
    int len = res.size();
    for(int i = 0; i < len; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
