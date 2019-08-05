#include <iostream>

using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        return ((num1&num2)<<1) + (num1^num2);
    }
};

int main()
{
    Solution s;
    cout << s.Add(100, 101);
    return 0;
}
