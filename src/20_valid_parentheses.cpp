#include<iostream>
#include<string.h>
using namespace::std;
class Solution {
public:
    bool isValid(string s) {
        string res;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                res+=s[i];
            }
            else{
                if(s[i]==')'){
                    if(res.back()!='(') return false;
                }
                if(s[i]==']'){
                    if(res.back()!='[') return false;
                }
                if(s[i]=='}'){
                    if(res.back()!='{') return false;
                }
                res.pop_back();
            }
        }
        return res.empty();
    }
};

int main(){

	Solution sol;
	string s = "([)]";

	cout<<sol.isValid(s)<<endl;
}
