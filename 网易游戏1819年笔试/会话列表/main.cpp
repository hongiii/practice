#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 200+10;
int t, n, arr[N], temp;
unordered_map<int, int> ump; //ump记录数字是否存在数组中，避免重复
int cnt; //记录不重复数据个数
int main(){
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &temp);
            if(ump.find(temp) == ump.end())
            {
                arr[cnt] = temp;
                ump[temp] = 1;
                cnt++;
            }
            else
            {
                int pos = 0, topdata = temp;
                for(int i = 0; i < cnt; i++)
                {
                    if(arr[i] == topdata)
                    {
                        pos= i;
                        break;
                    }
                }
                for(int j = pos; j < cnt-1; j++)
                {
                    arr[j] = arr[j+1];
                }
                arr[cnt-1] = topdata;
            }
        }
        for(int i = cnt-1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        ump.clear();
    }
    return 0;
}
