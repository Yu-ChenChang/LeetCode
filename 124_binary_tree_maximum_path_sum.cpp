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
public:
	int maxValue(TreeNode* root, int& max){
		if(root==NULL) return 0; 
		int lValue = maxValue(root->left,max);
		int rValue = maxValue(root->right,max);
		int cValue = root->val;
		if(lValue>0) cValue+=lValue;
		if(rValue>0) cValue+=rValue;
		max = cValue>max?cValue:max;
		int res = root->val;
		if(lValue>0&&lValue>rValue) return res+lValue;
		if(rValue>0&&rValue>lValue) return res+rValue;
		return res;
	}
    int maxPathSum(TreeNode* root) {
		int max=INT_MIN;
		maxValue(root,max);
		return max;	
    }
};


int main(){

}
