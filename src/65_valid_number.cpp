#include<iostream>
#include<string>
using namespace::std;

class Solution {
public:
	bool isDigit(char c){
		return c>='0'&&c<='9';
	}
    bool isNumber(string s) {
        //"1 1"is not valid, "0x11" is not valid, "." is not valid, "2e3.1" is not valid, "2e" is not valid,"1a" is not valid,"++1" is not valid
        int n = s.size();
        if(n == 0) return false;
        int i = 0;
        int countDigit = 0,countPoint = 0;
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
		//deal with '.' (must need number if use '.' && no more than one '.'
        while(isDigit(s[i]) || s[i] == '.') s[i++] == '.'?countPoint++:countDigit++;
        if(countPoint > 1 || countDigit < 1) return false;
		//if e appears
        if(s[i] == 'e'){
            i++;
            countDigit = 0;countPoint = 0;
            if(s[i] == '+' || s[i] == '-') i++;
            while(isDigit(s[i]) || s[i] == '.') s[i++] == '.'?countPoint++:countDigit++;
            if(countPoint > 0 || countDigit < 1) return false;
        }
        while(s[i] == ' ') i++;
        return i == n;
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
	cout<<sol.isNumber(" ")<<endl;;
	cout<<sol.isNumber(" a")<<endl;;
	cout<<sol.isNumber(". 1")<<endl;;
	cout<<sol.isNumber("e9")<<endl;;
	cout<<sol.isNumber(".")<<endl;;
	cout<<sol.isNumber("6+1")<<endl;;
	cout<<sol.isNumber("92e1740e91")<<endl;;
	cout<<sol.isNumber("1e+")<<endl;;
	cout<<sol.isNumber(".1e.8")<<endl;;
}
