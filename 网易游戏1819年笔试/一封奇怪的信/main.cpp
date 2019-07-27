#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;

const int MAX_LEN = 100;
const int N = 100+10;

int dis[N], n; //dis数组记录每个字母占用的间距
string str;

void solution()
{
    int len = str.length();
    int row = 1, lastrow = 0;
    int cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(cnt+dis[str[i]-'a'] <= 100) //可以填一行
        {
            cnt += dis[str[i]-'a'];
            lastrow = cnt;
        }
        else //重新开始一行
        {
            row++;
            cnt = lastrow = dis[str[i]-'a'];
        }
   //     cout << "test: " << row << " " << lastrow << endl;
    }
    cout << row << " " << lastrow << endl;
}
int main()
{
    for(int i = 0; i < 26; i++)
        cin >> dis[i];
    cin >> str;
    solution();
    return 0;
}
