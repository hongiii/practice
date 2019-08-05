#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverse(string &s, int beg, int ed)
    {
        if(beg >= ed)
            return;
        int i, j; char tmp;
        for(i = beg, j = ed; i < j; i++, j--)
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len <= 0) return str;
        n = n % len;

        reverse(str, 0, n-1);
        reverse(str, n, len-1);
        reverse(str, 0, len-1);
        return str;
    }
};

int main()
{
    Solution s;
    string str = "abcXYZdef";
    str = s.LeftRotateString(str, 3);
    cout << str << endl;
    return 0;
}
