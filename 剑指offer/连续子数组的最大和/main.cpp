#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if(len <= 0) return 0;
        int sum = array[0];
        int maxsum = array[0];
        for(int i = 1; i < len; i++)
        {
            if(sum <= 0)
                sum = array[i];
            else
                sum += array[i];
            if(sum > maxsum)
                maxsum = sum;
        }
        return maxsum;
    }
};

int main()
{
    Solution s;
    vector<int> t1{6,-3,-2,7,-15,1,2,2};
    vector<int> t2{1,-2,3,10,-4,7,2,-5};
    cout << s.FindGreatestSumOfSubArray(t1) << endl;
    cout << s.FindGreatestSumOfSubArray(t2) << endl;
    return 0;
}
