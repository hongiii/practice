#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣
//ע��Ҫ��������֮�䡢ż��֮������λ�ò���
//�������һ����ȥ���������ñ�Ľⷨ
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int odd = 0, even = 0;
        int *oddarr = new int[len+1];
        int *evenarr = new int[len+1];
        memset(oddarr, 0, sizeof(oddarr)*(len));
        memset(evenarr, 0, sizeof(evenarr)*(len));
        vector<int>::iterator it;
        for(it = array.begin(); it != array.end(); it++)
        {
            if((*it)%2 == 0)
                evenarr[even++] = *it;
            else
                oddarr[odd++] = *it;
        }
        array.clear();
        for(int i = 0; i < odd; i++)
            array.push_back(oddarr[i]);
        for(int i = 0; i < even; i++)
            array.push_back(evenarr[i]);
    }
};

void Test(const char *testname, vector<int> arr)
{
    Solution s;
    s.reOrderArray(arr);
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
    vector<int> arr2 = {3,4,6};
    vector<int> arr3;
    vector<int> arr4 = {1,3,5};
    Test("test1", arr1);
    Test("test2", arr2);
    Test("test3", arr3);
    Test("test4", arr4);
    return 0;
}
