#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

/**
 * Definition for undirected graph.
 **/
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	void helper(UndirectedGraphNode* res, UndirectedGraphNode* node, unordered_map<int,UndirectedGraphNode*>& umap){
		for(int i=0;i<node->neighbors.size();i++)
		{
			if(umap[node->neighbors[i]->label]!=NULL)
			{
				res->neighbors.push_back(umap[node->neighbors[i]->label]);
			}
			else
			{
				int label = node->neighbors[i]->label;
				UndirectedGraphNode* one = new UndirectedGraphNode(label);
				umap[label] = one;
				res->neighbors.push_back(one);
				helper(one, node->neighbors[i], umap);
			}
		}
	}
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node==NULL) return NULL;
		UndirectedGraphNode* res = new UndirectedGraphNode(node->label);
		unordered_map<int,UndirectedGraphNode*> umap;
		umap[node->label] = res;
		helper(res, node, umap);
		return res;
    }
};

int main(){

}
