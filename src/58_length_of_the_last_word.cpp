#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		if(s.empty()) return 0;
		int res=0;
		int i=s.size()-1;
		while(s[i]==' '&&i>=0) i--;
		for(;i>=0;i--)
		{
			if(s[i]!=' ')
			{
				res++;
			}
			else
				break;
		}
		return res;
    }
};

int main(){
	string str="Hello World ";
	Solution sol;
	cout<<sol.lengthOfLastWord(str)<<endl;


}
