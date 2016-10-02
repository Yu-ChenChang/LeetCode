#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<utility>
using namespace::std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
		size=0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
		int usize = umap[val].size();
		if(size==nums.size()){
			nums.push_back(pair<int,int>(val,usize));
		}
		else if(size<nums.size()){
			nums[size] = pair<int,int>(val,usize);
		}
		else{
			cerr<<"ERROR!"<<endl;
			return false;
		}
		umap[val].push_back(size);
		size++;
       	return true; 
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
		if(umap.find(val)==umap.end()) return false;
		else if(umap[val].empty()) return false;

		int nind = umap[val].back();
		size--;
		pair<int,int> last = nums[size];
		swap(nums[nind],nums[size]);
		umap[last.first][last.second] = nind;

		umap[val].pop_back();
		//if(umap[val].empty()) umap.erase(val);
		return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
		int randidx = rand()%size;
		return nums[randidx].first;
    }
private:
	vector<pair<int,int> > nums; // <val, index in umap vector>
	int size;
	unordered_map<int,vector<int> > umap; //<val, index>
};

int main(){

}
