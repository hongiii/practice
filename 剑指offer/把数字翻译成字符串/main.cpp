#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int countWays(char *str)
{
    if(str == nullptr)
        return 0;
    int count[100];
    memset(count, 0, sizeof(count));
    int cnt = 0;
    int len = strlen(str);

    for(int i = len-1; i >= 0; i--)
    {
        if(i < len-1)
        {
            cnt = count[i+1];
        }
        else
            cnt = 1;
        if(i < len-2)
        {
            int num = str[i] - '0';
            int bnum = str[i+1] - '0';
            if(num*10+bnum >= 10 && num*10+bnum <= 25)
                cnt += count[i+2];
            else
                cnt += 1;
        }
        count[i] = cnt;
    }
    return count[0];
}
int main()
{
    char test[] = "12258";
    cout << countWays(test) << endl;
    return 0;
}
