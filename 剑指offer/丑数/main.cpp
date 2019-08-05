#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    int findMinIn3Nums(int a, int b, int c)
    {
        return min(min(a, b), c);
    }
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        int *uglyArr = new int[index+10];
        uglyArr[1] = 1;
        int p2, p3, p5;
        p2 = p3 = p5 = 1;
        int cnt = 2;
        while(cnt <= index)
        {
            int minNum =
            findMinIn3Nums(uglyArr[p2]*2, uglyArr[p3]*3, uglyArr[p5]*5);
            uglyArr[cnt] = minNum;
            while(uglyArr[p2]*2 <= minNum) ++p2;
            while(uglyArr[p3]*3 <= minNum) ++p3;
            while(uglyArr[p5]*5 <= minNum) ++p5;
            cnt++;
        }
        int res = uglyArr[index];
        delete []uglyArr;
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.GetUglyNumber_Solution(1) << endl;
    cout << s.GetUglyNumber_Solution(2) << endl;
    cout << s.GetUglyNumber_Solution(4) << endl;
    cout << s.GetUglyNumber_Solution(40) << endl;
    return 0;
}
