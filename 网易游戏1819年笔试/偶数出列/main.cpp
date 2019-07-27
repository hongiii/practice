#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int a[10000+10] = {0};
//最后输出 = 最后一个出列的编号
int main()
{
    int cnt = 10000;
    while(cnt > 1)
    {
        int num = 0;
        for(int i = 1; i <= 10000; i++)
        {
            if(a[i] == 0)
            {
                num++;
                if(num%2 == 0)
                {
                    a[i] = -1;
                    cout << i << " ";
                }
            }
        }
    }
    return 0;
}
