#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100][100]; //ºŸ…Ë «100x100µƒ∆Â≈Ã
//int f[100][100];
int m, n;

int result()
{
    int **f = new int*[m+10];
    for(int i = 0
        ; i <= m; i++)
    {
        f[i] = new int[n+10];
    }
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                f[i][j] = 0;
            else
                f[i][j] = a[i][j];
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
    {
        f[i][j] = max(f[i-1][j], f[i][j-1])+ a[i][j];
    }
    return f[m][n];
}

int main()
{
    cin >> m >> n;
   // memset(f, 0, sizeof(f));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
    {
        scanf("%d", &a[i][j]);
      //  f[i][j] = a[i][j];
    }
    cout << result() << endl;
    return 0;
}

/*
4 4
1 10 3 8
12 2 9 6
5 7 4 11
3 7 16 5
*/
