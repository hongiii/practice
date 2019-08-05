#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
//���ݣ��ҵ�һ���㣬�Կ����ߵ�ѡ�񣬴���ѡһ�����������ߣ�����߲���ȥ�ˣ��ص���һ����㣬ȥ��������û�б��ѡ�����û�������Ϸ��ء�
//һֱ���ݵ����ϲ㣬����Ѿ�û�б��ѡ����˵���÷��������С�ֱ���ҵ�һ�����еĽ��������Ҳ����û�У�

//�������ݣ�
/*
���ܲ��ԣ��ȽϹ�ص�����
�߽���ԣ�����ֻ��һ�л���һ�У������·���ַ���ͬ
����������ԣ��ַ���Ϊ�գ����������������
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


