#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        int len = sequence.size();
        int root = sequence[len-1];
        int leftbeg = 0;
        while(leftbeg < len-1 && sequence[leftbeg] < root)
            leftbeg++;
        vector<int> left, right;
        for(int i = 0; i < leftbeg; i++)
            left.push_back(sequence[i]);

        for(int i = leftbeg; i < len-1; i++)
        {
            if(sequence[i] < root)
                return false;
            right.push_back(sequence[i]);
        }
        bool judgel = true, judger = true;
        if(left.size() >= 1) judgel = VerifySquenceOfBST(left);
        if(right.size() >= 1) judger = VerifySquenceOfBST(right);
        return judgel && judger;
    }
};

int main()
{
    Solution s;
    vector<int> vec{5, 7, 6, 9, 11, 10, 8};
    cout << s.VerifySquenceOfBST(vec) << endl;
    vector<int> vecc{7,4,6,5};
    cout << s.VerifySquenceOfBST(vecc) << endl;
    vector<int> veccc;
    cout << s.VerifySquenceOfBST(veccc) << endl;
    return 0;
}
