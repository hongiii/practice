#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//数组、排序链表、AVL树
//最大堆最小堆
//class Solution {
//public:
//    vector<int> vec;
//    void Insert(int num)
//    {
//        vec.push_back(num);
//    }
//
//    double GetMedian()
//    {
//        sort(vec.begin(), vec.end());
//        int len = vec.size();
//        if(len%2)
//            return vec[len/2];
//        else
//            return (vec[len/2] + vec[len/2-1])/2.0;
//    }
//
//};
class Solution {
public:
    void Insert(int num)
    {
        if(((min.size() + max.size())&1) == 0)
        {
            if(max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else
        {
            if(min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        int size = min.size() + max.size();
        if((size & 1) == 1)
            return min[0]*1.0;
        else
            return (min[0]+max[0])*1.0/2.0;
    }
private:
    vector<int> min;
    vector<int> max;
};
int main()
{
    //5,2,3,4,1,6,7,0,8
    Solution s;
    s.Insert(5);
    cout << s.GetMedian() << endl;
    s.Insert(2);
    cout << s.GetMedian() << endl;
    s.Insert(3);
    cout << s.GetMedian() << endl;
    s.Insert(4);
    cout << s.GetMedian() << endl;
    s.Insert(1);
    cout << s.GetMedian() << endl;
    s.Insert(6);
    cout << s.GetMedian() << endl;
    s.Insert(7);
    cout << s.GetMedian() << endl;
    return 0;
}
