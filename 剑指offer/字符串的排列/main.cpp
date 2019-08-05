#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;

void permutation(char *str);
void permutation(char *str, char *begin);

void permutation(char *str)
{
    if(str == nullptr)
        return;
    permutation(str, str);
}

void permutation(char *str, char *begin)
{
    if(*begin == '\0')
        printf("%s\n", str);
    else
    {
        for(char *ch = begin; *ch != '\0'; ch++)
        {
            char temp = *ch;
            *ch = *begin;
            *begin = temp;
            permutation(str, begin+1);

            temp = *ch;
            *ch = *begin;
            *begin = temp;
        }
    }
}

int main()
{
    char str[] = "abc";
    permutation(str);
    return 0;
}
