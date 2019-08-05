#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
//÷¡…ŸºÙ1µ∂
int solution(int len)
{
    if(len <= 0)
        return 0;
    if(len == 1)
        return 1;
    if(len == 2)
        return 1;
    if(len == 3)
        return 2;
    int *f = new int[len+10];
    f[1] = 1;
    f[2] = 2;
    f[3] = 3;
    for(int i = 4; i <= len; i++)
    {
        int maxi = 0;
        for(int j = 1; j <= (i+1)/2; j++)
        {
            if(f[j]*f[i-j] > maxi)
                maxi = f[j]*f[i-j];
            f[i] = maxi;
        }
    }
//    for(int i = 1; i <= 10; i++)
//    {
//        cout << f[i] << " ";
//    }
//    cout << endl;
    return f[len];
}

int solutionat(int len)
{
    if(len == 1)
        return 1;
    if(len == 2)
        return 1;
    if(len == 3)
        return 2;
    int times3 = len/3;
    int times2 = 0;
    if(len-times3*3 == 1)
        times3 -= 1;
    times2 = (len-times3*3)/2;
    return (int)(pow(3, times3)) * (int)(pow(2, times2));
}
int main()
{
    int n;
    cin >> n;
    cout << solution(n) << endl;
    cout << solutionat(n) << endl;
    return 0;
}
