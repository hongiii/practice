#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        string str;
        int sum = 0, m = 0;
        for(int i = 1; i <= n; i++)
        {
            str = to_string(i);
            m = count(str.begin(), str.end(), '1');
            sum = sum + m;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    cout << s.NumberOf1Between1AndN_Solution(21) << endl;
    return 0;
}
