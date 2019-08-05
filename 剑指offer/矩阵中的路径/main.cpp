#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
//回溯，找到一个点，对可以走的选择，从中选一个出来继续走，如果走不下去了，回到上一个结点，去看看还有没有别的选择，如果没有再往上返回。
//一直回溯到最上层，如果已经没有别的选择了说明该方案不可行。直至找到一条可行的解决方案（也可能没有）

//测试数据：
/*
功能测试：比较规矩的输入
边界测试：矩阵只有一行或者一列，矩阵和路径字符相同
特殊输入测试：字符串为空，行列输入有问题等
*/
class Solution {
public:
    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char *str, int len, bool vis[])
    {
        if(str[len] == '\0')
            return true;
        bool res = false;
        if(row >= 0 && col >= 0 && row < rows && col < cols && !vis[row*cols+col] && matrix[row*cols+col] == str[len])
        {
            vis[row*cols+col] = true;
            len++;
            res = hasPathCore(matrix, rows, cols, row-1, col, str, len, vis) ||
                hasPathCore(matrix, rows, cols, row, col-1, str, len, vis) ||
                hasPathCore(matrix, rows, cols, row+1, col, str, len, vis) ||
                hasPathCore(matrix, rows, cols, row, col+1, str, len, vis);
            if(!res)
            {
                vis[row*cols+col] = false;
                len--;
            }
        }
        return res;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
             return false;

        bool *visited = new bool[rows*cols+1];
        memset(visited, 0, rows*cols);
        int length = 0;
         for(int i = 0; i < rows; i++)
         {
             for(int j = 0; j < cols; j++)
             {
                 if(hasPathCore(matrix, rows, cols, i, j, str, length, visited))
                 {
                     return true;
                 }
             }
         }
        delete []visited;
        return false;
    }

};

int main()
{
    Solution s;
    char matrix[] = "abtgcfcsjdeh";
    char t1[] = "bfce";
    char t2[] = "abfb";
    char matrixT[] = "aaaaaa";
    char t3[] = "aaa";
    cout << s.hasPath(matrix, 3, 4, t1) << endl;
    cout << s.hasPath(matrix, 3, 4, t2) << endl;
    cout << s.hasPath(matrixT, 2, 3, t3) << endl;
    return 0;
}


