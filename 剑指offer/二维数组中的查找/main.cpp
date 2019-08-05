#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    if(array.empty())
        return false;
    int row = array.size();
    int col = array[0].size();
    for(int j = col-1; j >= 0; j--)
    {
        if(array[0][j] == target)
            return true;
        else if(array[0][j] > target)
            continue;
        for(int i = 1; i < row; i++)
        {
            if(array[i][j] == target)
            {
                return true;
            }
            else if(array[i][j] < target)
            {
                continue;
            }
            else
                break;
        }
    }
    return false;
}

int main()
{
    vector<vector<int> > arr{{1,2,8,9}, {2,4,9,12}, {4, 7, 10,13}, {6, 8, 11, 15}};
    cout << Find(7, arr) << endl;
    cout << Find(0,arr) << endl;
    cout << Find(15,arr) << endl;
    return 0;
}
