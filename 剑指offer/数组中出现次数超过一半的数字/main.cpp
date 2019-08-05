#include <iostream>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len <= 0) return 0;
        if(len == 1) return numbers[0];
        int times = 1; int val = numbers[0];
        for(int i = 1; i < len; i++)
        {
            if(numbers[i] == val)
                ++times;
            else
                --times;
            if(times == 0)
            {
                val = numbers[i];
                times = 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < len; i++)
        {
            if(numbers[i] == val)
                cnt++;
        }
        if(cnt*2 > len)
            return val;
        else
            return 0;
    }
};
//class Solution {
//public:
//    int MoreThanHalfNum_Solution(vector<int> numbers) {
//        int len = numbers.size();
//        if(len <= 0) return 0;
//        if(len == 1) return numbers[0];
//        sort(numbers.begin(), numbers.end());
//        int num = numbers[len/2];
//        int cnt = 0;
//        for(int i = 0; i < len; i++)
//            if(numbers[i] == num)
//                cnt++;
//        if(cnt > len/2)
//            return num;
//        else
//            return 0;
//    }
//};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
