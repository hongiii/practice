#include <iostream>
#include <algorithm>
using namespace std;
//借助数组实现的建议哈希表，时间复杂度O(n) 空间复杂度O(1)
//O(n^2)
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int len = str.length();
        if(len <= 0) return -1;
        for(int i = 0; i < len; i++)
        {
            if(count(str.begin(), str.end(), str[i]) == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
