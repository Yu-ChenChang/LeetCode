#include<vector>
#include<string>
#include<iostream>
using namespace::std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		int dot = 0, dot2 = 0;
		while(dot<version1.size() || dot2<version2.size()){
			int left1 = atoi(version1.c_str()+dot);
			int left2 = atoi(version2.c_str()+dot2);
			if(left1>left2) return 1;
			else if(left1<left2) return -1;
			for(;dot<version1.size();dot++){
				if(version1[dot]=='.'){
					dot++;
					break;
				}
			}
			for(;dot2<version2.size();dot2++){
				if(version2[dot2]=='.'){
					dot2++;
					break;
				}
			}
		}
		return 0;
    }
};

int main(){
	Solution sol;
	cout<<sol.compareVersion("1.0.1","1.1")<<endl;

}
