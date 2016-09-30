#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n,1);
        for(int i=2;i*i<n;i++){
            if(dp[i]==0) continue;
            
            for(int j=i;i*j<n;j++){
                dp[i*j]=0;
            }
        }
        int res=0;
        for(int i=2;i<n;i++)
            if(dp[i]==1) res++;
        return res;
    }
};

int main(){

}
