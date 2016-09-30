#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s.empty()&&t.empty()) return true;
        unordered_map<char,char> stotmap;
        unordered_map<char,bool> used;
        int len = s.size();
        for(int i=0;i<len;i++){
            if(stotmap.find(s[i])!=stotmap.end()){//find s
                if(stotmap[s[i]]!=t[i]) return false;
            }
            else{
                if(used[t[i]]) return false;
                stotmap[s[i]]=t[i];
                used[t[i]]=true;
            }
        }
        return true;
    }
};

int main(){

}
