#include<iostream>
#include<vector>
#include<string.h>
using namespace::std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        
        string prefix = strs[0];
        int i=1,j=0;
        for(;i<strs.size();i++){
            for(j=0;j<strs[i].size()&&j<prefix.size();j++){
                if(prefix[j]!=strs[i][j]){
                    break;
                }
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
    }
};
int main(){
	vector<string> strs;
	Solution sol;
	cout<<sol.longestCommonPrefix(strs)<<endl;	

}
