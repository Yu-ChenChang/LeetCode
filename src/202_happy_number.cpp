#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    bool isHappy(int n) {
		unordered_map<int,bool> umap;        
		while(umap[n]==false){
			umap[n] = true;
			int res = 0;
			while(n){
				res += (n%10)*(n%10);
				n/=10;
			}
			n = res;
			if(n==1) return true;
		}
		return false;
    }
};

int main(){
}
