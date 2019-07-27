#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1000+10;
int arr[N];
int n = 0, len = 0, tmp;
int main()
{
    while(~scanf("%d", &tmp))
    {
        arr[n++] = tmp;
    }
    sort(arr, arr+n);
    arr[n] = -1;
    int sum = 0;
    for(int i = 0; i < n;)
    {
        if(arr[i] == 0)
        {
            sum++;
            i++;
        }
        if(arr[i] != arr[i+1])
        {
            sum += arr[i]+1;
            i++;
        }
        else if(arr[i] == arr[i+1])
        {
            int j = i+1;
            int num = 1;
            while(j < n && arr[j] == arr[i])
            {
                num++;
                j++;
            }
            if(num <= arr[i])
            {
                 sum += arr[i]+1;
            }
            else if(num > arr[i])
            {
                sum += (arr[i]+1)*(num/(arr[i]+1));
                if(num%(arr[i]+1))
                    sum += arr[i]+1;
            }
            i = j;
        }
     //   cout << arr[i]  << " " << sum << endl;
    }
    cout << sum << endl;
}
