#include <iostream>
#include <exception>
#include <cmath>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    double powbase(double base, int exponent)
    {
        if(exponent == 0)
            return 1.0;
        if(exponent == 1)
            return base;
        double res = powbase(base, exponent>>1);
        res *= res;
        if((exponent&1) == 1)
            res *= base;
        return res;
    }
    double Power(double base, int exponent) {
        if(fabs(base-0.0) < 1.0e-15)
            return 0.0;
        int flag = 0;
        if(exponent < 0)
        {
            exponent = -exponent;
            flag = 1;
        }
        double res = powbase(base, exponent);
        if(flag)
            return 1.0/res;
        else
            return res;
    }
};
//class Solution {
//public:
//    double Power(double base, int exponent) {
//        double res = 1.0;
//        if(exponent == 0)
//            return res;
//        if(fabs(base-0.0)<=1.0e-15)
//            return 0;
//        int flag = 0;
//        if(exponent < 0)
//        {
//            flag = 1;
//            exponent = -exponent;
//        }
//        for(int i = 0; i < exponent; i++) //这里可以改进
//             res *= base;
//        if(flag)
//        {
//            return 1.0/res;
//        }
//        else
//            return res;
//    }
//
//};

int main()
{
    Solution s;
    cout << s.Power(2, -3) << endl;
    cout << s.Power(0, -3) << endl;
    return 0;
}
