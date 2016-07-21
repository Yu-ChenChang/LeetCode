#include<iostream>
#include<string.h>
#include<vector>
#include<map>
using namespace::std;

class Solution {
public:
	void printmap(map<string,int> mp){
		for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
			cout<<it->first<<" "<<it->second<<endl;
		}	
	}
    vector<int> findSubstring(string S, vector<string> &L) {
		map<string,int> mp;
		vector<int> res;
		for(int i=0;i<L.size();i++){
			if(mp.find(L[i])==mp.end()){
				mp.insert(pair<string,int>(L[i],1));
			}else{
				mp[L[i]]++;
			}
		}
		int len = L[0].size();
		int size = L.size();
		map<string,int> curmp;
		//printmap(mp);
		
		bool flag=false;
		if(S.size()<len*size) return res;
		for(int i=0;i<S.size()-len*size+1;i++){
			string subString = S.substr(i,len);
			if(mp.find(subString)!=mp.end()){
				flag=true;
				for(int j=i;j<i+len*size;j+=len){
					subString = S.substr(j,len);
					if(mp.find(subString)!=mp.end()){
						if(curmp[subString]==mp[subString]){
							flag=false;
							break;
						}
						curmp[subString]++;	
					}
					else{
						flag=false;
						break;
					}
				}
				if(flag){
					res.push_back(i);	
				}
			}
			curmp.clear();
		}	
		return res;	
    }
};


int main(){
	Solution sol;
	string S = "a";//bcdefghhhhhh";
	string s1= "a";
	//string s2= "abc";
	//string s3= "ghh";
	vector<string> L;
	L.push_back(s1);
	//L.push_back(s2);
	//L.push_back(s3);
	vector<int> res = sol.findSubstring(S,L);
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
