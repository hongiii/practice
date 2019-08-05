#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    int InversePairsCore(vector<int>& data, vector<int> &copy, int start, int ed)
    {
        if(start == ed)
        {
            copy[start] = data[start];
            return 0;
        }
        int mid = start + (ed-start)/2;
        int left = InversePairsCore(copy, data, start, mid)%1000000007;
        int right = InversePairsCore(copy, data, mid+1, ed)%1000000007;

        int i = mid;
        int j = ed;
        int indexArray = ed;
        int cnt = 0;
        while(i >= start && j >= mid+1)
        {
            if(data[i] > data[j])
            {
                copy[indexArray--] = data[i--];
                cnt += j - mid;
                cnt %= 1000000007;
            }
            else
            {
                 copy[indexArray--] = data[j--];
            }
        }
        for(; i >= start; i--)
             copy[indexArray--] = data[i];
        for(; j >= mid+1; j--)
             copy[indexArray--] = data[j];
        return (left+right+cnt)%1000000007;
    }
    int InversePairs(vector<int> data) {
        int len = data.size();
        if(len <= 1) return 0;
        vector<int> copy;
        for(int i = 0; i < len; i++)
            copy.push_back(data[i]);
        int count = InversePairsCore(data, copy, 0, len-1);
        return count;
    }
};
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,0};
    vector<int> bec{7,5,6,4};
    Solution s;
    cout << s.InversePairs(vec) << endl;
    cout << s.InversePairs(bec) << endl;
    return 0;
}
