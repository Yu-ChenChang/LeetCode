#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    string convertToTitle(int n) {
		string res = "";
		while(n){
			int r = n%26;
			n /= 26;
			if(r==0){
				res += 'Z';
				n--;
			}else{
				res += 'A'+r-1;
			}
		}
		reverse(res.begin(),res.end());
		return res;
    }
};

int main(){
	Solution sol;
	cout<<sol.convertToTitle(17576)<<endl;

}
