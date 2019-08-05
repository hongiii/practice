#include <iostream>

using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length < 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;
        }
        sort(numbers, numbers+length);
        int top = 0;
        bool res = false;
        for(int i = 1; i < length; i++)
        {
            if(numbers[i] == numbers[i-1])
            {
                *duplication = numbers[i];
                res = true;
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length <= 0)
            return false;
        for(int i = 0; i < length; i++)
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;

        unordered_map<int, int> mp;
        for(int i = 0; i < length; i++)
        {
            if(mp.find(numbers[i]) == mp.end())
                mp[numbers[i]] = 1;
            else
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;

    }
};

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length <= 0)
            return false;
        for(int i = 0; i < length; i++)
            if(numbers[i] < 0 || numbers[i] > length-1)
                return false;

        for(int i = 0; i < length; i++)
        {
            if(numbers[i] == i)
                 continue;
            while(numbers[i] != i)
            {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                else
                {
                    int tmp =  numbers[i];
                    numbers[i] = numbers[tmp];
                    numbers[tmp] = tmp;
                }
            }
        }
        return false;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
