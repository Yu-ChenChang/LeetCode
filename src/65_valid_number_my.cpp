#include<iostream>
#include<string>
using namespace::std;

class Solution {
public:
    bool isNumber(string s) {
		if(s.empty()) return false;
		int i=0;
		//remove in front space
		while(i<s.size() && s[i]==' ') i++;
		if(i==s.size()) return false;

		//number area (start with number(0-9) ,'-' ,'+' ,'.')
		//number before 'e'
		bool exp = 0;
		bool sign = 0;
		bool dot = 0;
		bool needN = 0;
		bool validN = 0;
		while(i<s.size())
		{
			if(s[i]>='0'&&s[i]<='9')
			{
				sign=1;
				needN = 0;
				validN =1;
			}
			else
			{
				if(needN) return false;
				else if(s[i]=='+'||s[i]=='-')
				{
					if(sign) return false;
					sign = 1;
				}
				else if(s[i]=='.')
				{
					if(dot) return false;
					dot = 1;
					sign= 1;
					if(s[i-1]<'0' || s[i-1]>'9') needN = 1;
				}
				else if(s[i]=='e')
				{
					if(!validN) return false;
					exp = 1;
					i++;
					break;
				}
				else if(s[i]==' ')
					break;
				else
					return false;
			}
			i++;
		}
		if(s[i-1]=='e'&&i==s.size() || !validN) return false;
		//number afer 'e'
		if(exp)
		{
			sign = 0;
			needN = 0;
			validN = 0;
			while(i<s.size())
			{
				if(s[i]>='0'&&s[i]<='9')
				{
					sign=1;
					needN = 0;
					validN = 1;
				}
				else
				{
					if(needN) return false;
					else if(s[i]=='+'||s[i]=='-')
					{
						if(sign) return false;
						sign = 1;
					}
					else if(s[i]==' ')
						break;
					else
						return false;
				}
				i++;
			}
			
		}

		//remove backward space
		while(i<s.size()&&s[i]==' ') i++;
		if(i!=s.size() || needN || !validN) return false;
		else return true;        
    }
};

int main(){
	Solution sol;
	cout<<"==========1=========="<<endl;
	cout<<sol.isNumber("0")<<endl;
	cout<<sol.isNumber("1 ")<<endl;
	cout<<sol.isNumber(" 0.1")<<endl;
	cout<<sol.isNumber("2e-10")<<endl;;
	cout<<sol.isNumber("3.")<<endl;;
	cout<<sol.isNumber(".1")<<endl;;
	cout<<sol.isNumber("+.8")<<endl;;
	cout<<sol.isNumber("46.e8")<<endl;;
	cout<<sol.isNumber("2e0")<<endl;;
	cout<<"=========0=========="<<endl;
	cout<<sol.isNumber(" a")<<endl;;
	cout<<sol.isNumber(". 1")<<endl;;
	cout<<sol.isNumber("e9")<<endl;;
	cout<<sol.isNumber(".")<<endl;;
	cout<<sol.isNumber("6+1")<<endl;;
	cout<<sol.isNumber("92e1740e91")<<endl;;
	cout<<sol.isNumber("1e+")<<endl;;
	cout<<sol.isNumber(".1e.8")<<endl;;
}
