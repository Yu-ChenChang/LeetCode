#include<iostream>
#include<string.h>
using namespace::std;
class Solution {
public:
    bool isValid(string s) {
		string left;
		int len=0;
       	for(int i=0;i<s.size();i++){
			if(s[i]=='('||s[i]=='['||s[i]=='{'){
				left+=s[i];
				len++;
			}
			else{
				if(left[len-1]=='('&&s[i]==')'){
					left.erase(len-1);
					len--;
				}
				else if(left[len-1]=='['&&s[i]==']'){
					left.erase(len-1);
					len--;
				}
				else if(left[len-1]=='{'&&s[i]=='}'){
					left.erase(len-1);
					len--;
				}
				else{
					return 0;
				}
			}
		} 
		if(!left.empty())
			return 0;	
		else 
			return 1;
    }
};

int main(){

	Solution sol;
	string s = "([)]";

	cout<<sol.isValid(s)<<endl;
}
