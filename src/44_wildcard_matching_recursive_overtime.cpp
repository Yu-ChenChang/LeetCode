#include<iostream>
#include<vector>
using namespace::std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(),p.c_str());
    }
    
    bool isMatch(const char *s, const char *p) {
        if(*p=='\0')
            return *s=='\0';    
        if(*p!='*') {
            if(*s==*p)
                return isMatch(s+1,p+1);
            if(*p=='?' && *s!='\0')
                return isMatch(s+1,p+1);
            return false;
        }
        while(*s!='\0') {
            if(isMatch(s,p+1)) 
                return true ;
            s++;
        }
        return isMatch(s,p+1);        
    }
};

int main(){
	string s = "aa";
	string p = "aa";
	Solution sol;
	cout<<sol.isMatch(s,p)<<endl;

}
