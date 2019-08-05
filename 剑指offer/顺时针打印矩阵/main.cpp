#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row <= 0)
            return res;
        int col = matrix[0].size();
        int i, j, x = 0;
        row = row - 1, col = col - 1;
        do
        { //后两个if很重要，从右往左、从下往上的方向是否有必要（分别对应只有一行和一列的情况）
            for(i = x, j = x; j <= col; j++) res.push_back(matrix[i][j]);
            for(i = x+1, j = col; i <= row; i++) res.push_back(matrix[i][j]);
            if(x != row) for(i = row, j = col-1; j >= x; j--) res.push_back(matrix[i][j]);
            if(x != col) for(i = row-1, j = x; i > x; i--) res.push_back(matrix[i][j]);
            ++x, --row, --col;
        }while(x <= row && x <= col);
//        vector<int>::iterator it = res.begin();
//        for(; it != res.end(); it++)
//        {
//            cout << *it << " ";
//        }
//        cout << endl;
        return res;
    }
};

int main()
{
    vector<vector<int> > vec{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    Solution s;
    s.printMatrix(vec);
    vector<vector<int> > vec1{{1}, {2}, {3}, {4}, {5}};
    s.printMatrix(vec1);
    vector<vector<int> >vec2{{1,2,3,4,5}};
    s.printMatrix(vec2);
    vector<vector<int> >vec3{{1,2,3}, {4,5,6}, {7,8,9}};
    s.printMatrix(vec3);
    return 0;
}
