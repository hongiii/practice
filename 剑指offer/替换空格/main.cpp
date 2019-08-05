#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length == 0)
            return;
        static char *des = (char*)malloc(sizeof(char)*length*2);
        int beg = 0, cnt = 0;;
        for(int i = 0; i < length; i++)
        {
            if(str[i] != ' ')
            {
                des[cnt++] = str[i];
            }
            else if(str[i] == ' ')
            {
                des[cnt++] = '/%';
                des[cnt++] = '2';
                des[cnt++] = '0';
                beg = i+1;
            }
        }
        des[cnt] = '\0';
        strcpy(str, des);
       // cout << des << endl;
	}
};
//δָ��length���壬��֮ǰ��Ϊ���ַ������ȣ���������д����������������ַ��������Ļ���������strcpy�ķ���Ҳ�����ˡ�
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length <= 0)
            return;
        int i = 0, numOfBlank = 0, originLen = 0;
        while(str[i] != '\0')
        {
            originLen++;
            if(str[i] == ' ')
                numOfBlank++;
            i++;
        }
        int newLen = originLen + numOfBlank*2;
        if(newLen > length)
            return;
        while(originLen < newLen && originLen >= 0)
        {
            if(str[originLen] == ' ')
            {
                str[newLen--] = '0';
                str[newLen--] = '2';
                str[newLen--] = '\%';
            }
            else
            {
                str[newLen--] = str[originLen];
            }
            --originLen;
        }
	}
};

int main()
{
    Solution s;
    char str[] = "we are happy";
    s.replaceSpace(str, 12);
    cout << str << endl;
    return 0;
}
