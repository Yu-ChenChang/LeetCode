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
	vector<TreeNode *> generateTrees(int n) {
		if(!n) return vector<TreeNode*>(1,NULL);
		vector<vector<vector<TreeNode*> > > subTrees(n+2, vector<vector<TreeNode*> >(n+2,vector<TreeNode*>()));
		
		for(int i=1;i<=n+1;i++)
		{
			subTrees[i][i].push_back(new TreeNode(i));
			subTrees[i][i-1].push_back(NULL);
		}
		
		for(int nodeNum=2;nodeNum<=n;nodeNum++)
			for(int i=1;i<=n-nodeNum+1;i++)
				for(int root=i;root<=i+nodeNum-1;root++)
					for(int leftChildNum=0;leftChildNum<subTrees[i][root-1].size();leftChildNum++)
						for(int rightChildNum=0;rightChildNum<subTrees[root+1][i+nodeNum-1].size();rightChildNum++)
						{
							TreeNode* node = new TreeNode(root);
							node->left = subTrees[i][root-1][leftChildNum];
							node->right = subTrees[root+1][i+nodeNum-1][rightChildNum];
							subTrees[i][i+nodeNum-1].push_back(node);
						}


		return subTrees[1][n];
	}
};

int main(){

}
