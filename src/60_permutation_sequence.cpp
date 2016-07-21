#include<iostream>
#include<vector>
#include<string>
using namespace::std;

class Solution {
public:
	int level(int k){
		int res = 1;
		for(int i=1;i<=k;i++)
			res *=i;
		return res;
	}

    string getPermutation(int n, int k) {
		string res;
		int curN = n-1;
		int curNLevel = level(n-1);
		k--;

		int num[n];
		int size = n;
		for(int i=0;i<n;i++)
			num[i] = i+1;

		for(int i=0;i<n;i++)
		{
			int Index = k/curNLevel;
			res += '0' + num[Index];
			size--;
			for(int j=Index;j<size;j++)
				num[j] = num[j+1]; 
			k %= curNLevel;	
			if(curN>1)
			{
				curNLevel /=curN;
				curN--;
			}
		}

		return res;
    }
};

int main(){
	Solution sol;
	for(int n=1;n<=3;n++)
	{
		for(int k=1;k<=sol.level(n);k++)
		{
			string res = sol.getPermutation(n,k);
			cout<<res<<endl;
		}
	}

}
