#include <iostream>
#include <algorithm>
using namespace std;
//��������ʵ�ֵĽ����ϣ��ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
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
