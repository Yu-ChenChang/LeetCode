#include<algorithm>
#include<vector>
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
	vector<vector<int> > pathSum(TreeNode* root, int sum) {
		if(root==NULL) return vector<vector<int> >();
		vector<vector<int> > res;
		searchPath(root,sum,vector<int>(),res);
		return res;
	}
private:
	void searchPath(TreeNode* root, int sum, vector<int> cur, vector<vector<int> > &res){
		sum -= root->val;
		cur.push_back(root->val);
		if(root->left==NULL && root->right==NULL){
			if(sum==0){
				res.push_back(cur);
			}
		}
		if(root->left!=NULL){
			searchPath(root->left, sum, cur, res);
		}
		if(root->right!=NULL){
			searchPath(root->right, sum, cur, res);
		}
		return;
	}
};

int main(){

}
