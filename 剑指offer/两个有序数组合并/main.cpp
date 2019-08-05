#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solution(int a[], int an, int b[], int bn)
{
    if(b == nullptr)
        return;
    if(a == nullptr)
    {
        for(int i = 0; i < bn; i++)
        {
            a[i] = b[i];
        }
        return;
    }
    int newAn = an+bn;
    an = an-1;
    bn = bn-1;
    while(newAn > 0)
    {
        if(b[bn] > a[an])
        {
            a[--newAn] = b[bn];
            bn--;
        }
        else
        {
            a[--newAn] = a[an];
            an--;
        }
        if(an < 0 && bn >= 0)
        {
            for(int i = bn; i >= 0; i--)
            {
                a[--newAn] = b[bn];
                bn--;
            }
        }
        cout << "test: " << newAn << " ";
        for(int i = 0; i < 10; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int a[10] = {2,4,5};
    int b[3] = {1,3,6};
    //int b[3] = {2,3,6};
    solution(a, 3, b, 3);
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
