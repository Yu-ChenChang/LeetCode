#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace::std;

class TwoSum {
public:
    // Add the number to an internal data structure.
	void add(int number) {
		umap[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
		for(unordered_map<int,int>::iterator it = umap.begin();it!=umap.end();it++){
			int mapv = it->first;
			if((value-mapv==mapv)&& umap[value-mapv]==2 || (value-mapv!=mapv) && umap.find(value-mapv)!=umap.end()) return true;
		}
		return false;
	}
private:
	unordered_map<int,int> umap;
};

int main(){
}
