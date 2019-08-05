#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> vec;
        int len = array.size();
        if(len <= 0) return vec;
        int beg = 0, ed = len-1, min = array[len-1]*array[len-1];
        int num1, num2, flag = 0;
        while(beg < ed)
        {
            while(array[beg] + array[ed] > sum && beg < ed)
                ed--;
            while(array[beg] + array[ed] < sum && beg < ed)
                beg++;
      //      cout << array[beg] << " " << array[ed] << endl;
            if(beg < ed && array[beg] + array[ed] == sum)
            {
                flag = 1;
                cout << array[beg] << " " << array[ed] << endl;
                if(array[beg] * array[ed] < min)
                {
                    min = array[beg] * array[ed];
                    num1 = array[beg];
                    num2 = array[ed];
                }
                ed--;
            }
        }
        if(flag)
        {
            vec.push_back(num1);
            vec.push_back(num2);
        }
        return vec;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {1,2,4,7,8,11,15};
    vector<int> res = s.FindNumbersWithSum(vec, 15);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
