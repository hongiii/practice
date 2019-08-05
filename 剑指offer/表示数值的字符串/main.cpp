#include <iostream>

using namespace std;

class Solution {
public:
    bool unsignedIntegerScan(char **str)
    {
        const char *con = *str;
        while(**str != '\0' && **str >= '0' && **str <= '9')
            ++(*str);
   //     cout << con << " " << *str << endl;
        return con < *str;
    }
    bool integerScan(char **str)
    {
        if(**str == '+' || **str == '-')
            ++(*str);
        return unsignedIntegerScan(str);
    }
    bool isNumeric(char* string)
    {
         if(string == nullptr)
             return false;
         bool num = integerScan(&string);
         if(*string == '.')
         {
             string++;
             num = unsignedIntegerScan(&string) || num;
         }
         if(*string == 'e' || *string == 'E')
         {
             string++;
             num = integerScan(&string) && num;
         }
         return num && *string == '\0';
    }

};

void Test(const char *testname,  char *str, bool expected)
{
    Solution s;
    printf("%s ", testname);
    if(s.isNumeric(str) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}
int main()
{
    Test("test1", "12", true);
    Test("test2", ".3", true);
    Test("test3", "4.", true);
    Test("test3", "4.e", false);
    return 0;
}
