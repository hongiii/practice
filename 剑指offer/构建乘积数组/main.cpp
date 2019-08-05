#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B;
        if(len <= 0)
            return B;
        for(int i = 0; i < len; i++)
            B.push_back(1);
        for(int i = 1; i < len; i++)
            B[i] = B[i-1]*A[i-1];
        int temp = 1;
        for(int i = len-2; i >= 0; i--)
        {
            temp *= A[i+1];
            B[i] *= temp;
        }
        return B;
    }
};
int main()
{
    Solution s;
    vector<int> vec = {1,2,4,3};
    vector<int> res = s.multiply(vec);
    int len = res.size();
    for(int i = 0; i < len; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
