#include<iostream>
using namespace::std;

class Solution{
public:
	bool isUgly(int num){
		int prime[] = {2,3,5};
		for(int i=0;i<3 && num; i++)
			while(num%prime[i] == 0)
				num /=prime[i];
		return num==1;
	}
};

int main(){
	Solution sol;
	cout<<sol.isUgly(20)<<endl;
	cout<<sol.isUgly(21)<<endl;
	

}
