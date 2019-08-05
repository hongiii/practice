#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    string res;
    static int cmp(int num1, int num2)
    {
        string str1= "", str2 = "";
        str1 += to_string(num1);
        str1 += to_string(num2);
        str2 += to_string(num2);
        str2 += to_string(num1);
        return str1 < str2;
    }
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len <= 0) return res;
        sort(numbers.begin(), numbers.end(), cmp);
        string tmp;
        for(int i = 0; i < len; i++)
        {
            tmp = to_string(numbers[i]);
            res += tmp;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> vec{3,32,321};
    cout << s.PrintMinNumber(vec) << endl;
    return 0;
}
