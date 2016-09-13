#include<vector>
#include<list>
#include<unordered_map>
#include<string>
#include<utility>
#include<iostream>
using namespace::std;

class LRUCache{
public:
    LRUCache(int capacity) {
       mcapacity = capacity; 
    }
    
    int get(int key) {
		if(mumap.find(key)==mumap.end()) return -1;
		else{
			moveFront(key,mumap[key]->second);
			return mumap[key]->second;
		}
    }
    
    void set(int key, int value) {
		if(mumap.find(key)!=mumap.end()){
			moveFront(key,value);
		}
		//not found in cache
        else{
			if(mcache.size()>=mcapacity){
				list<pair<int,int> >::iterator it = --mcache.end();
				mumap.erase(it->first);//
				mcache.pop_back();
			}
			mcache.push_front(pair<int,int>(key,value));
			mumap[key] = mcache.begin();
		}
    }
private:
	unordered_map<int, list<pair<int,int> >::iterator > mumap; // <key, pair<key,value> >
	list<pair<int,int> > mcache; // <key, value>
	int mcapacity;
	void moveFront(int key, int value){
		list<pair<int,int> >::iterator it = mumap[key];
		mcache.erase(it);
		mcache.push_front(pair<int,int>(key,value));
		mumap[key] = mcache.begin();
	}
};

int main(){
	class LRUCache lru(2);
	lru.set(2,1);
	lru.set(1,1);
	cout<<lru.get(2)<<endl;
	lru.set(4,1);
	cout<<lru.get(1)<<endl;
	cout<<lru.get(2)<<endl;


}
