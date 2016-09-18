#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<utility>
using namespace::std;

/**
 * Definition for a binary tree node.
 **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if(!root) return res;
		queue<pair<int,TreeNode*> > que;
		que.push(pair<int,TreeNode*>(0,root));
		int curI = 0;
		while(!que.empty()){
			pair<int,TreeNode*> curp = que.front();
			que.pop();
			if(curp.first==curI){
				res.push_back(curp.second->val);
				curI++;
			}
			if(curp.second->right) que.push(pair<int,TreeNode*>(curp.first+1,curp.second->right));
			if(curp.second->left) que.push(pair<int,TreeNode*>(curp.first+1,curp.second->left));
		}
		return res;
    }
};

int main(){

}
