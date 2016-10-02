#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace::std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
		size=0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		if(umap.find(val)!=umap.end()){
			return false;
		}
		if(size==elements.size())
			elements.push_back(val);
		else if(size<elements.size())
			elements[size] = val;
		else{
			cerr<<"ERROR!"<<endl;
		}
		umap[val] = size;
		size++;
		return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
		if(umap.find(val)==umap.end()){
			return false;
		}
		int ind = umap[val];
		size--;
		swap(elements[ind],elements[size]); //swap the deleted one to the end
		umap[elements[ind]] = ind; //update the new num in ind
		umap.erase(val); //update the original one
		return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
		if(size>0){
			int ranidx = rand()%size;
			return elements[ranidx];
		}
		else return 0;
    }
private:
	vector<int> elements; //<num>
	int size; //real size of nums in elements
	unordered_map<int,int> umap; //<num,index>
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(){
	int val = 10;
	RandomizedSet obj; 
	cout<<obj.insert(val)<<endl;
	cout<<obj.remove(val)<<endl;
	cout<<obj.getRandom()<<endl;
 
}
