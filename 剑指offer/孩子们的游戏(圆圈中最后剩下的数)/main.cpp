#include <iostream>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    list<int> ls;
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 0 || m < 1)
            return -1;
        for(int i = 0; i < n; i++)
            ls.push_back(i);
        list<int>::iterator it = ls.begin();
        while(ls.size() > 1)
        {
            for(int i = 1; i < m; i++)
            {
                it++;
                if(it == ls.end())
                    it = ls.begin();
            }
            list<int>::iterator next = ++it;
            if(next == ls.end())
            {
                next = ls.begin();
            }
            it--;
            ls.erase(it);
            it = next;
        }
        return (*it);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
