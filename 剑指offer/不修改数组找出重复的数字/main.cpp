#include <iostream>

using namespace std;

class Solution {
public:
    //½èÖú¸¨Öú¿Õ¼ä
    bool finddup(const int numbers[], int length, int *duplication) {
        if(numbers == nullptr || length <= 0)
            return false;
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] >= length || numbers[i] < 1)
                return false;
        }
        int extraArr[length] = {0};
        int cnt = 0;
        for(int i = 0; i < length; i++)
        {
            if(extraArr[numbers[i]] == 0)
            {
                extraArr[numbers[i]] = 1;
                cnt++;
            }
            else
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
    bool findDup(const int nums[], int length, int *duplications)
    {
        if(nums == nullptr || length <= 0)
            return false;
        int beg = 1, ed = length-1;
        while(beg <= ed)
        {
            int mid = ((ed-beg)>>1) + beg;
            int cnt = countNums(nums, length, beg, mid);
            cout << beg << " " << mid << " " << ed << " " << cnt << endl;
            if(beg == ed)
            {
                if(cnt > 1)
                {
                    *duplications = beg;
                    return true;
                }
                else
                    break;
            }
            if(cnt <= (mid-beg+1))
                beg = mid+1;
            else
                ed = mid;
        }
        return false;
    }
    int countNums(const int nums[], int length, int start, int ed)
    {
        if(nums == nullptr)
            return 0;
        int res = 0;
        for(int i = 0; i < length; i++)
        {
            if(nums[i] >= start && nums[i] <= ed)
                res++;
        }
        return res;
    }
};
int main()
{
    int nums[10] = {1,3,5,4,3,2,6,7};
    Solution s;
    int *p = new int();
    cout << s.findDup(nums, 8, p) << endl;
    cout << *p << endl;
    return 0;
}
