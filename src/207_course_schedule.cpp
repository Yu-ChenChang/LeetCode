#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>(0));
		vector<int> visit(numCourses, 0);
		for (auto a : prerequisites) {
			graph[a[1]].push_back(a[0]);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!canFinishDFS(graph, visit, i)) return false;
		}
		return true;
	}
	bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
		if (visit[i] == -1) return false;
		if (visit[i] == 1) return true;
		visit[i] = -1;
		for (auto a : graph[i]) {
			if (!canFinishDFS(graph, visit, a)) return false;
		}
		visit[i] = 1;
		return true;
	}
};
int main(){

}
