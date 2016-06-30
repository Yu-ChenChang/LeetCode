#include<iostream>
#include<string.h>
using namespace::std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        for(int i=0;i<(int)haystack.size()-(int)needle.size()+1;i++)
        {
            bool same = true;
            for(int j=0;j<(int)needle.size();j++)
            {
                if(haystack[i+j]!=needle[j])
                {
                    same = false;
                }
            }
            if(same) return i;
        }
        return -1;
    }
};
int main(){

}
