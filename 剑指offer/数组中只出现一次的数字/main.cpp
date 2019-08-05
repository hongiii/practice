#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find1bit(int num)
    {
        int index = 0;
        while(((num&1) == 0) && (index < 8*sizeof(int)))
        {
            num = num >> 1;
            index++;
        }
     //   cout << index << endl;
        return index;
    }
    bool is1bit(int num, int index)
    {
        num = num >> index;
        return (num & 1) == 1;
    }
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len = data.size();
        if(len <= 0) return;
        int num = 0;
        for(int i = 0; i < len; i++)
        {
            num = num ^ data[i];
        }
       // cout << num << endl;
        int index = find1bit(num);
        *num1 = *num2 = 0;
        for(int i = 0; i < len; i++)
        {
            if(is1bit(data[i], index))
                *num1 = (*num1) ^ data[i];
            else
                *num2 = (*num2) ^ data[i];
        }
    }
};

int main()
{
    vector<int> vec{2,4,3,6,3,2,5,5};

    Solution s;
    int *n1 = new int;
    int *n2 = new int;
    s.FindNumsAppearOnce(vec, n1, n2);
    cout << *n1 << " " << *n2 << endl;
    return 0;
}
