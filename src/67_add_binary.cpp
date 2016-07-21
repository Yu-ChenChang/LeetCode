#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace::std;
class Solution {
public:
    string addBinary(string a, string b) {
		string res;
		int i = a.size()-1;
		int j = b.size()-1;
		bool carry = 0;
		while(i>=0 && j>=0)
		{
			char value = a[i--]-'0' + b[j--];
			if(carry){
				value++;	
				carry=0;
			}
			if(value>='2')
			{
				value-=2;
				carry=1;
			}
			res.push_back(value);
		}
		while(i>=0||j>=0)
		{
			char value = i>=0?a[i--]:b[j--];
			if(carry){
				value++;
				carry=0;
			}
			if(value>='2')
			{
				value-=2;
				carry=1;
			}
			res.push_back(value);
		}
		if(carry) res.push_back('1');
		reverse(res.begin(),res.end());
		return res;
    }
};

int main(){
	string a="11";
	string b="1";
	Solution sol;
	cout<<sol.addBinary(a,b)<<endl;

	a="1010";
	b="1011";
	cout<<sol.addBinary(a,b)<<endl;
}
