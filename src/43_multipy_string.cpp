#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

class Solution {
public:
    string multiply(string num1, string num2) {
		if(num1[0]=='0'||num2[0]=='0') return "0";
		string res;
		int carry = 0;
		int size1 = num1.size();
		int size2 = num2.size();
		int* value = new int[size1+size2-1]();
		for(int i=0;i<size1;++i)
			num1[i] = num1[i]-'0';
		for(int i=0;i<size2;++i)
			num2[i] = num2[i]-'0';

		for(int i=0;i<size1;++i)
		{
			for(int j=0;j<size2;++j)
			{
				value[i+j]+= num1[i]*num2[j];
			}	
		}
		for(int i=size1+size2-2;i>0;i--)
		{
			value[i-1] += value[i]/10;
			value[i] %= 10;
			res += (value[i]+'0');
		}
		while(value[0])
		{
			res += (value[0]%10+'0');
			value[0]/=10;
		}	
		reverse(res.begin(),res.end());
		return res;
    }
};

int main(){
	string num1 = "99";
	string num2 = "100";
	cin>>num1>>num2;
	Solution sol;
	cout<<sol.multiply(num1,num2)<<endl;
	
}
