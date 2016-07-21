#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> res;
        vector<string> copy = strs;
        for(int i=0;i<copy.size();i++)
        {
            sort(copy[i].begin(),copy[i].end());
        }
        unordered_map<string,int> unmap;
        for(int i=0;i<copy.size();i++)
        {
            if(unmap[copy[i]]==0)
            {
                unmap[copy[i]] = i+1;
            }
            else if(unmap[copy[i]]!=-1)
            {
                res.push_back(strs[unmap[copy[i]]-1]);
                res.push_back(strs[i]);
                unmap[copy[i]] = -1;
            }
            else res.push_back(strs[i]);
        }
        return res;
    }
};

int main(){
	string str = "dcba";
	sort(&str[0],&str[0]+4);
	cout<<str<<endl;
}
