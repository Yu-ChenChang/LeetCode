#include<vector>
#include<string>
#include<iostream>
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
	vector<TreeNode *> generateTrees(int st,int ed){
		vector<TreeNode *> res;
		if(ed-st<0) res.push_back(0);
		if(ed-st==0) res.push_back(new TreeNode(st));
		if(ed-st>0)
		{
			for(int i=st;i<=ed;i++)
			{
				vector<TreeNode *> l = generateTrees(st,i-1);
				vector<TreeNode *> r = generateTrees(i+1,ed);

				for(int li=0;li<l.size();li++)
					for(int ri=0;ri<r.size();ri++)
					{
						TreeNode* cur = new TreeNode(i);
						cur->left = l[li];
						cur->right = r[ri];
						res.push_back(cur);
					}
			}
		}
		return res;
	}
	vector<TreeNode *> generateTrees(int n) {
		return generateTrees(1,n);	
	}
};

int main(){

}
