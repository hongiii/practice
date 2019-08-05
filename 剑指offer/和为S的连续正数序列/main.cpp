#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum <= 2) return res;
        vector<int> vec;
        int beg = 1, ed = 2;
        int cnt = 3;
        while(beg+1 <= ed && ed <= ceil(sum/2.0))
        {
      //      cout << "1" << endl;
            while(cnt < sum)
            {
                ed++;
                cnt += ed;
            }
            while(cnt > sum)
            {
                cnt -= beg;
                beg++;
            }
            cout << "Test: " << beg << " " << ed << " " << cnt << endl;
            if(cnt == sum)
            {
                for(int i = beg; i <= ed; i++)
                {
                    vec.push_back(i);
                    cout << i << " ";
                }
                cout << endl;
                res.push_back(vec);
                vec.clear();
                ed++;
                cnt += ed;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    s.FindContinuousSequence(8);
    return 0;
}
