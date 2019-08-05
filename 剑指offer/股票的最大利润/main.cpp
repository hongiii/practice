#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    int maxDiff(vector<int> nums)
    {
        int len = nums.size();
        if(len <= 0)
            return 0;
        int minx = INT_MAX;
        int maxdiff = 0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] < minx)
                minx = nums[i];
            if(nums[i] - minx > maxdiff)
                maxdiff = nums[i] - minx;
        }
        return maxdiff;
    }
};

int main()
{
    vector<int> vec = {9, 11, 8, 5, 7, 12, 16, 14};
    Solution s;
    cout << s.maxDiff(vec) << endl;
    return 0;
}
