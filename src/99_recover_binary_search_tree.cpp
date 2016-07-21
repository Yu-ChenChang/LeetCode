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

//http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root,*prev = NULL;
		TreeNode* first=NULL,*second=NULL;
		TreeNode* preValue = NULL;
		while(cur!=NULL)
		{
			if(cur->left==NULL)
			{
				//output cur->val
				if(preValue!=NULL&&preValue->val>cur->val)
				{
					if(first==NULL) first = preValue;
					second = cur;
				}
				preValue = cur;
				cur = cur->right;
				continue;
			}

			//finding prev 
			prev = cur->left;
			while(prev->right!=NULL&&prev->right!=cur) prev = prev->right;

			if(prev->right==NULL)
			{
				prev->right = cur;
				cur = cur->left;
				continue;
			}

			//output cur->val
			if(preValue!=NULL&&preValue->val>cur->val)
			{
				if(first==NULL) first = preValue;
				second = cur;
			}
			preValue = cur;
			cur = cur->right;
			prev->right = NULL;
		}
		swap(first->val,second->val);
    }
};

int main(){

}
