#include<iostream>
#include<vector>
#include<string.h>
using namespace::std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> res;
		if(digits==""){
			 string one = "";
			 res.push_back(one);
			 return res;
		}
		char mapping[10][5]= {
				{0},{0},
				{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
				{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
		};	
		int ptr[digits.size()];
		for(int i=0;i<digits.size();i++){
			ptr[i] = 0;
		}
		int round=1;
		for(int i=0;i<digits.size();i++){
			round*=5;
		}
		for(int r=0;r<round;r++){
			string one;	
			for(int i=0;i<digits.size();i++){
				one+=mapping[digits[i]-'0'][ptr[i]];
			}
			res.push_back(one);
			ptr[0]++;
			for(int j=0;j<digits.size()-1;j++){
				if(mapping[digits[j]-'0'][ptr[j]]==0||ptr[j]>4){
					ptr[j]=0;
					ptr[j+1]++;
				}
			}
			if(mapping[digits[digits.size()-1]-'0'][ptr[digits.size()-1]]==0||ptr[digits.size()-1]>4){
				break;
			}
		}	
		return res;
    }
};

int main(){
	
	Solution sol;
	string phone="23244";
	vector<string> res = sol.letterCombinations(phone);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

}
