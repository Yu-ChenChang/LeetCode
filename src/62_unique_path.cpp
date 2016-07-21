#include<iostream>
using namespace::std;

class Solution {
public:
    double level(int end,int start){
        double res=1;
        for(int i=start;i<=end;i++)
            res*=i;
        return res;
	}
    int uniquePaths(int m, int n) {
        int start = m>n?m:n;
        return level(m-1+n-1,start)/level(m+n-start-1,1);
    }
};

int main(){
	Solution sol;
	cout<<sol.uniquePaths(10,10)<<endl;

}
