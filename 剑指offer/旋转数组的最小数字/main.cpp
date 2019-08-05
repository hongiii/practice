#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if(len <= 0) return 0;
        int index1 = 0, index2 = len-1;
        int indexMid = index1;
        if(rotateArray[index1] < rotateArray[index2-1])
        {
            return rotateArray[index1];
        }
        while(rotateArray[index1] >= rotateArray[index2])
        {
            if(index2-index1 == 1)
            {
                indexMid = index2;
                break;
            }
            indexMid = (index2 + index1)/2;
            if(rotateArray[indexMid] == rotateArray[index1] && rotateArray[indexMid] == rotateArray[index2])
            {
                for(int i = index1+1; i < index2; i++)
                {
                    if(rotateArray[i] < rotateArray[indexMid])
                    {
                        indexMid = i;
                    }
                }
                break;
            }
            if(rotateArray[index1] <= rotateArray[indexMid])
                index1 = indexMid;
            else
                index2 = indexMid;
        }
        return rotateArray[indexMid];
    }
};

int main()
{
    return 0;
}
