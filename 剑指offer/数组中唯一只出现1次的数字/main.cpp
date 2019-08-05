#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solution(vector<int> num, int* target)
{
    int len = num.size();
    if(len <= 0) return;
    int bits[32] = {0};
    vector<int> vec(num);
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(((num[j]>>i)&1) == 1)
                bits[i]++;
        }
        bits[i] %= 3;
    }
    *target = 0;
    for(int i = 0; i < 32; i++)
    {
        cout << bits[i] << " ";
        if(bits[i])
        {
            *target += (1 << i);
        }
    }
    cout << endl;
    return;
}

int main()
{
    vector<int> a = {-1,-1,-2,-1};
    int *res = new int;
    solution(a, res);
    cout << *res << endl;
    return 0;
}
