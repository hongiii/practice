#include <iostream>

using namespace std;

class Solution {
public:
    void reverse(string &s, int beg, int ed)
    {
        if(beg >= ed)
            return;
        int i, j;
        char tmp;
        for(i = beg, j = ed; i < j; i++, j--)
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    string ReverseSentence(string str) {
        int len = str.length();
        if(len <= 0)
            return str;
        reverse(str, 0, len-1);
        cout << str << endl;
        int beg = 0, ed = 1;
        for(; ed < len; ed++)
        {
            if(str[ed] == ' ')
            {
                reverse(str, beg, ed-1);
                beg = ed+1;
                ed++;
            }
            if(ed == len - 1)
            {
                reverse(str, beg, ed);
            }
        }
        return str;
    }
};

int main()
{
    string str = "iir am a student.";
    string str1 = "i";
    string str2 = "";
    string str3 = "student. a am I";
    Solution s;
    cout << s.ReverseSentence(str) << endl;
    cout << s.ReverseSentence(str1) << endl;
    cout << s.ReverseSentence(str2) << endl;
    cout << s.ReverseSentence(str3) << endl;
    return 0;
}
