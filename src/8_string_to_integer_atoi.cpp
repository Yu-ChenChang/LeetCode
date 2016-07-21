#include<iostream>
#include <stdlib.h>
#include<string>
using namespace::std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool sign = false;
        bool neg = false;
        bool num = false;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                if(num==true) break;
            }
            else if(str[i]=='-' || str[i]=='+')
            {
                if(str[i]=='-') neg = true;
                if(sign == true) return 0;
                sign = true;
                num = true;
            }
            else if(str[i]>='0'&&str[i]<='9')
            {
                num=true;
                if(res<INT_MIN/10) return neg?INT_MIN:INT_MAX;
                res*=10;
                if(res<INT_MIN+(str[i]-'0')) return neg?INT_MIN:INT_MAX;
                res-=(str[i]-'0');
            }
            else break;
        }
        return neg?res:(res==INT_MIN?INT_MAX:-res);
    }
};

int main(int argc,char** argv){

}

