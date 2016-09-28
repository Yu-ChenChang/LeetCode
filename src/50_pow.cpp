#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	double myPow(double x, int n) {
		unordered_map<int,double> umap;
		bool negn = (n<0);
		if(n>0) n = -n;
		double res = 1;
		int pow = -1;
		double num = x;
		umap[pow] = num;
		while(pow>n&&pow>=INT_MIN/2){
			pow *= 2;
			num *= num;
			umap[pow] = num;
		}
		while(n<0){
			while(n<=pow){
				n-=pow;
				res*=umap[pow];
			}
			pow /= 2;
		}
		return negn?1/res:res;
	}
};

int main(){
	Solution sol;
	cout<<sol.myPow(2,10)<<endl;
	cout<<sol.myPow(0.00001, 2147483647)<<endl;
	cout<<sol.myPow(2,-2147483648)<<endl;
	cout<<(int)abs(-2147483648)<<endl;
}
