#include<vector>
#include<string>
#include<iostream>
#include<stack>
using namespace::std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		int res = 0;
		stack<int> nums;
		for(int i=0;i<tokens.size();i++){
			if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
				int right = nums.top();
				nums.pop();
				int left = nums.top();
				nums.pop();
				if(tokens[i]=="+")
					res = left+right;
				if(tokens[i]=="-")
					res = left-right;
				if(tokens[i]=="*")
					res = left*right;
				if(tokens[i]=="/")
					res = left/right;
				nums.push(res);
			}
			else{
				nums.push(atoi(tokens[i].c_str()));
			}
		}
		return res;
    }
};

int main(){

}
