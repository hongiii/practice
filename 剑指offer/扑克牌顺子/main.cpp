#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int len = numbers.size();
        if(len <= 0) return false;
        sort(numbers.begin(), numbers.end());
        int numof0 = 0;
        for(int i = 0; i < len; i++)
            if(numbers[i] == 0)
                numof0++;
        int cnt = 0;
        for(int i = numof0+1; i < len; i++)
        {
        //    cout << numbers[i] - numbers[i-1] << endl;
            if(numbers[i] - numbers[i-1] > 1)
                cnt += numbers[i] - numbers[i-1] - 1;
            if(numbers[i] == numbers[i-1])
                return false;
            if(numof0 < cnt)
                return false;
        }
        return true;
    }
};

int main()
{
    vector<int> res = {1,3,2,4,6};
    Solution s;
    cout << s.IsContinuous(res);
    return 0;
}
