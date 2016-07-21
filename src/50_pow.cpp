#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    double myPow(double x, int n) {
		unordered_map<int,double> umap;
		bool sign = n>0?1:0;
		n = abs(n);
		int pow=1;
		double res=1;
		for(pow=1;pow<<1 <=n && pow<<1>0;pow<<=1)
		{
			umap[pow] = x;
			x *=x;
		}
		umap[pow] = x;
		while(pow>0&&n>0)
		{
			if(pow<=n)
			{
				res *= umap[pow];
				n -= pow;
			}
			pow/=2;
		}
		return sign>0?res:1/res;
    }
};

int main(){
	Solution sol;
	cout<<sol.myPow(2,10)<<endl;
	cout<<sol.myPow(0.00001, 2147483647)<<endl;
	cout<<sol.myPow(2,-2147483648)<<endl;
	cout<<(int)abs(-2147483648)<<endl;
}
