#include <iostream>

using namespace std;

int  NumberOf1(int n) {
         int res = 0;
         int flag = 1;
         while(flag != 0)
         {
             if((n&flag) != 0)
                 res++;
             flag = flag << 1;
         }
         return res;
     }

int main()
{
    cout << NumberOf1(-1) << endl;
    cout << NumberOf1(-2) << endl;
    cout << NumberOf1(4) << endl;
    cout << NumberOf1(10) << endl;
    return 0;
}
