#include<vector>
#include<string>
#include<iostream>
#include<stack>
#include<queue>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if(root==NULL) return res;
		stack<TreeNode*> st;
		stack<int> reverse_res;
		TreeNode* ptr = NULL;
		st.push(root);
		while(!st.empty()){
			ptr = st.top();
			st.pop();
			reverse_res.push(ptr->val);
			if(ptr->left) st.push(ptr->left);
			if(ptr->right) st.push(ptr->right);
		}
		while(!reverse_res.empty()){
			res.push_back(reverse_res.top());
			reverse_res.pop();
		}
		return res;
    }
};

int main(){

}
