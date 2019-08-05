#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

int longestSubString(const string &s)
{
    int len = s.length();
    if(len <= 0)
        return 0;
    if(len == 1)
        return 1;
    int maxlen = 0;
    int *pos = new int[26];
    for(int i = 0; i < 26; i++)
        pos[i] = -1;
    int *f = new int[len+1];
    for(int i = 0; i < len; i++)
        f[i] = 0;
    maxlen = f[0] = 1;
    pos[s[0]-'a'] = 0;
    for(int i = 1; i < len; i++)
    {
        int prepos = pos[s[i] - 'a'];
        if(prepos == -1 || i - prepos > f[i-1])
        {
            f[i] = f[i-1]+1;
        }
        else
        {
            f[i] = i-prepos;
        }
        if(f[i] > maxlen)
                maxlen = f[i];
        pos[s[i] - 'a'] = i;
        cout << f[i] << endl;
    }
    return maxlen;
}

int main()
{
    string s = "arabcacfr";
    string t = "pwwkew";
    cout << longestSubString(s) << endl;
    cout << "--------" << endl;
    cout << longestSubString(t) << endl;

    return 0;
}
