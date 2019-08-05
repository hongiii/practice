#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();
        if(len == 0) return 0;
        int left = 0, right = len-1;
        int find = -1;
        while(left <= right)
        {
            int mid = (right+left)>>1;
            if(data[mid] == k)
            {
                find = mid;
                break;
            }
            else if(data[mid] > k)
                right = mid-1;
            else
                left = mid+1;
        }
        if(find == -1) return 0;
        int cnt = 0;
        for(int i = find; i < len; i++)
        {
            if(data[i] != data[find])
                break;
            cnt++;
        }
        for(int i = find-1; i >= 0; i--)
        {
            if(data[i] != data[find])
                break;
            cnt++;
        }
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> vec{1,2,3,3,4,4,5};
    cout << s.GetNumberOfK(vec, 1) << endl;
    cout << s.GetNumberOfK(vec, 2) << endl;
    cout << s.GetNumberOfK(vec, -1) << endl;
    cout << s.GetNumberOfK(vec, 3) << endl;
    return 0;
}
