#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    multiset<int, greater<int> > ms;
//    multiset<int, greater<int> >::iterator ims;
//    vector<int> res;
//    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//        int len = input.size();
//        if(len <= 0 || k > len || k <= 0)
//            return res;
//        for(int i = 0; i < k; i++)
//            ms.insert(input[i]);
//        for(int i = k; i < len; i++)
//        {
//            ims = ms.begin();
//            if(input[i] < *ims)
//            {
//                ms.erase(ims);
//                ms.insert(input[i]);
//            }
//        }
//        ims = ms.begin();
//        for(; ims != ms.end(); ims++)
//        {
//            res.push_back(*ims);
//            cout << *ims << " ";
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//};

class Solution {
public:
    vector<int> result;
    int Partition(vector<int>& input, int beg, int ed)
    {
        int base = input[beg];
        int i = beg, j = ed;
        while(i < j)
        {
      //      cout << i << " " << j << endl;
            while(input[j] >= base && i < j)
                j--;
            while(input[i] <= base && i < j)
                i++;
            if(i < j)
            {
                int tmp = input[i];
                input[i] = input[j];
                input[j] = tmp;
            }
        }
        input[beg] = input[i];
        input[i] = base;
        return i;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if(len <= 0 || k <= 0 || k > len)
            return result;
        int beg = 0, ed = len-1;
        int index = Partition(input, beg, ed);
        while(index != k-1)
        {
            if(index < k-1)
            {
                beg = index+1;
                index = Partition(input, beg, ed);
            }
            else
            {
                ed = index-1;
                index = Partition(input, beg, ed);
            }
        }
        for(int i = 0; i < k; i++)
        {
             result.push_back(input[i]);
             cout << input[i] << " ";
        }
        sort(result.begin(), result.end());
        return result;
    }
};
int main()
{
    vector<int> vec{4,5,1,6,2,7,3,8};
    Solution s;
    s.GetLeastNumbers_Solution(vec, 4);
    return 0;
}
