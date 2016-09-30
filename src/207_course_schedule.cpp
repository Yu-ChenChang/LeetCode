#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
		unordered_map<int, int> premap;//<node id, number of prereq>
		for(int i=0;i<numCourses;i++) premap[i] = 0;
		unordered_map<int, vector<int> > folmap; // <node id, all other nodes that take this node as prereq>
		for(int i=0;i<prerequisites.size();i++){
			premap[prerequisites[i].first]++;
			folmap[prerequisites[i].second].push_back(prerequisites[i].first);
		}
		helper(numCourses,prerequisites,premap,folmap);
		return (!numCourses);
    }
	void helper(int& numCourses, vector<pair<int, int> >& prerequisites,unordered_map<int, int>& premap,unordered_map<int,vector<int> >& folmap){
		unordered_map<int,int>::iterator it=premap.begin();
		while(it!=premap.end()){
			if(it->second!=0) it++;
			else{
				numCourses--;
				int curnode = it->first;
				premap.erase(it);
				it = premap.begin();
				for(int i=0;i<folmap[curnode].size();i++){
					premap[folmap[curnode][i]]--;
				}
			}
		}
	}
};

int main(){

}
