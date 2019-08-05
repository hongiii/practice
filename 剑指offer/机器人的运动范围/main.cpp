#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//深搜，一直往下走，不需要标记恢复。
class Solution {
public:
    bool judge(int threshold, int rows, int cols)
    {
        int sum = 0;
        while(rows)
        {
            sum += rows%10;
            rows /= 10;
        }
        while(cols)
        {
            sum += cols%10;
            cols /= 10;
        }
      //  cout << sum << " " << rows << " " << cols << endl;
        return sum <= threshold;
    }
    void dfs(int threshold, int rows, int cols, int x, int y, int visited[500][500], int &result, int mov[4][2])
    {
        if(!judge(threshold, x, y))
            return;
        for(int i = 0; i < 4; i++)
        {
            int newx = x + mov[i][0];
            int newy = y + mov[i][1];
            if(newx >= 0 && newx < rows && newy >=0 && newy < cols && !visited[newx][newy] && judge(threshold, newx, newy))
            {
                visited[newx][newy] = 1;
                result++;
       //         cout << newx << " " << newy << endl;
                dfs(threshold, rows, cols, newx, newy, visited, result, mov);
            }
        }
        return;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0)
            return 0;
        if(threshold == 0)
            return 1;

        int vis[500][500];
        memset(vis, 0, sizeof(vis));
        int mov[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        int res = 1;
        vis[0][0] = 1;
        dfs(threshold, rows, cols, 0, 0, vis, res, mov);
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.movingCount(2,4,3) << endl;
    cout << s.movingCount(0, 1, 1) << endl;
    return 0;
}
