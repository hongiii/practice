#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
//修改，把判断条件抽象出来，可以使用函数指针
class Solution {
public:
    void reOrderArray(vector<int> &array, bool (*func)(int)) {
        int len = array.size();
        if(len <= 0)
            return;
        int beg = 0, ed = len-1;
        while(beg < ed)
        {
            while(!func(array[beg])&& beg < ed)
                beg++;
            while(func(array[ed]) && beg < ed)
                ed--;
            if(beg < ed)
            {
                int tmp = array[beg];
                array[beg] = array[ed];
                array[ed] = tmp;
            }
        }
    }
};

bool isEven(int n)
{
    return (n&1) == 0;
}
void Test(const char *testname, vector<int> arr)
{
    Solution s;
    s.reOrderArray(arr, &isEven);
    vector<int>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr1 = {1,2,3,4,5,6};
    vector<int> arr2 = {2,4,6};
    vector<int> arr3;
    vector<int> arr4 = {2,4,6,1,3,5};
    Test("test1", arr1);
    Test("test2", arr2);
    Test("test3", arr3);
    Test("test4", arr4);
    return 0;
}
