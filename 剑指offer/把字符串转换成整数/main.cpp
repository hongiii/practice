#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int len = str.length();
        if(len == 0)
            return 0;
        string res;
        int flag = 0;
        for(int i = 0; i < len; i++)
        {
            if(i == 0 && !flag && str[0] == '+')
                continue;
            if(i == 0 && !flag && str[0] == '-')
            {
                flag = -1;
                continue;
            }
            if(str[i] >= '0' && str[i] <= '9')
                res.push_back(str[i]);
            else
                return 0;
        }
        int size = res.length();
    //    cout << res << endl;
        int result = 0;
        for(int i = 0; i < size; i++)
        {
            if(i != 0)
                result *= 10;
            result += res[i]-'0';
   //         cout << result << endl;
        }
        str.clear();
        if(flag == -1)
            return result*(-1);
        else
            return result;
    }
};

int main()
{
    Solution s;
    cout << s.StrToInt("-2147483647") << endl;
    cout << s.StrToInt("+123") << endl;
    cout << s.StrToInt("-123") << endl;
    cout << s.StrToInt("12a3") << endl;
    cout << s.StrToInt("1+23") << endl;
    return 0;
}
