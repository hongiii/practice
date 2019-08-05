#include <iostream>

using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    string s;
    int a[256] = {0};
    void Insert(char ch)
    {
        s += ch;
        a[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(a[s[i]] == 1)
            {
                return s[i];
            }
        }
        return '#';
    }

};

int main()
{
    return 0;
}
