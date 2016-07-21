#include<string.h>
#include<iostream>
using namespace::std;
class Solution {
public:
    int romanToInt(string s) {
        int idx = 0;
        int res = 0;
        while(idx<s.size())
        {
            if(s[idx]=='M') res+=1000;
            if(s[idx]=='D') res+=500;
            if(s[idx]=='C')
            {
                if(s[idx+1]=='M')
                {
                    res+=900;
                    idx++;
                }
                else if(s[idx+1]=='D')
                {
                    res+=400;
                    idx++;
                }
                else res+=100;
            }
            if(s[idx]=='L') res+=50;
            if(s[idx]=='X')
            {
                if(s[idx+1]=='C')
                {
                    res+=90;
                    idx++;
                }
                else if(s[idx+1]=='L')
                {
                    res+=40;
                    idx++;
                }
                else res+=10;
            }            
            if(s[idx]=='V') res+=5;
            if(s[idx]=='I')
            {
                if(s[idx+1]=='X')
                {
                    res+=9;
                    idx++;
                }
                else if(s[idx+1]=='V')
                {
                    res+=4;
                    idx++;
                }
                else res+=1;
            }
            idx++;
        }
        return res;
    }
};
int main(){
	string rom="MCMXCIX";
	Solution sol;
	cout<<sol.romanToInt(rom)<<endl;

}
