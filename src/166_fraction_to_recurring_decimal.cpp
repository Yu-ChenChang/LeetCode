#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace::std;
/**
 * Definition for an interval.
 **/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		if(numerator==0 || denominator==0) return "0";
		string res;
		if(numerator<0 ^ denominator<0) res+='-';
		long long nu = abs((long long)numerator);
		long long de = abs((long long)denominator);
		res += to_string(nu/de);
		long long diff = nu%de;
		if(!diff) return res;
		res += '.';
		unordered_map<long long,int> umap;
		while(diff){
			if(umap[diff]>0){
				res.insert(umap[diff],1,'(');
				res+=')';
				break;
			}
			umap[diff] = res.size();
			diff*=10;
			res += to_string(diff/de);
			diff %=de;
				
		}
		return res;
    }
};

int main(){
	Solution sol;
	cout<<sol.fractionToDecimal(1,5)<<endl;
	cout<<sol.fractionToDecimal(-1,-2147483648)<<endl;
}
