#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//注意小时部分的判断，测试情况：89,29,24
string s;
int n;
int hour, miniute, second;
int judge[10];

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        cin >> s;

        hour = (s[0]-'0')*10+(s[1]-'0');
        miniute = (s[3]-'0')*10+(s[4]-'0');
        second = (s[6]-'0')*10+(s[7]-'0');

        memset(judge, 0, sizeof(judge));
        if(hour >= 0 && hour <= 23)
            judge[0] = 1;
        if(miniute >= 0 && miniute <= 59)
            judge[1] = 1;
        if(second >= 0 && second <= 59)
            judge[2] = 1;
      //  cout << hour << " " << miniute << " " << second << endl;
      //  cout << judge[0] << " " << judge[1] << " " << judge[2] << endl;
        if(!judge[0])
        {
            if(hour > 23)
            {
                s[0] = '0';
            }
        }
        if(!judge[1])
        {
            if(s[3]-'0' >= 6) s[3] = '0';
        }
        if(!judge[2])
        {
            if(s[6]-'0' >= 6) s[6] = '0';
        }
        cout << s << endl;
    }
}
