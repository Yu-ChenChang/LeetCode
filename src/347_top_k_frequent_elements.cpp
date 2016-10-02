#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace::std;

struct compare{
  bool operator()(pair<int,int>& l, pair<int,int>& r){
      return l.second<r.second;
  }  
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty()) return res;
        priority_queue<pair<int,int>,vector<pair<int,int> >, compare> pq;
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for(unordered_map<int,int>::iterator it=umap.begin();it!=umap.end();it++){
            pq.push(pair<int,int>(it->first,it->second));
        }
        for(int i=0;i<k && !pq.empty();i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main(){

}
