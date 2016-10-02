#include<vector>
#include<string>
#include<iostream>
#include<utility>
#include<map>
using namespace::std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
		vector<pair<int,int> > res;
		if(buildings.empty()) return res;
		int begin = 0, end = buildings.size()-1;
		res = mergesort(buildings,begin,end);
		return res;
    }
private:
	vector<pair<int, int> > mergesort(vector<vector<int> >& buildings, int begin, int end){
		if(begin==end){
			vector<pair<int, int> > sol;
			sol.push_back(pair<int,int>(buildings[begin][0],buildings[begin][2])); //<x index, height>
			sol.push_back(pair<int,int>(buildings[begin][1],0)); 
			return sol;
		}
		int mid = (begin+end)>>1;
		vector<pair<int, int> > lres = mergesort(buildings,begin,mid);
		vector<pair<int, int> > rres = mergesort(buildings,mid+1,end);
		//merge
		vector<pair<int, int> > res;
		int li = 0, ri = 0;
		int h1 = 0, h2 = 0, hmax=0;
		while(li<lres.size() && ri<rres.size()){
			if(lres[li].first<rres[ri].first){
				h1 = lres[li].second;
				hmax=max(h1,h2);
				lres[li].second = hmax;
				if(nredundant(res,lres[li])) res.push_back(pair<int,int>(lres[li]));
				li++;
			}
			else{
				h2 = rres[ri].second;
				hmax=max(h1,h2);
				rres[ri].second = hmax;
				if(nredundant(res,rres[ri])) res.push_back(pair<int,int>(rres[ri]));
				ri++;
			}
		}
		while(li<lres.size()){
			if(nredundant(res,lres[li])) res.push_back(lres[li]);
			li++;
		}
		while(ri<rres.size()){
			if(nredundant(res,rres[ri])) res.push_back(rres[ri]);
			ri++;
		}
		return res;
	}
	bool nredundant(vector<pair<int,int> >& res, pair<int,int>& cur){
		if(!res.empty() && res.back().second==cur.second)
			return false;
		if(!res.empty() && res.back().first==cur.first){
			res.back().second = cur.second;
			return false;
		}
		return true;
	}
};

int main(){
	vector<vector<int> > buildings = {{2,5,2},{4,6,3},{3,5,4}};
	Solution sol;
	vector<pair<int, int> > res = sol.getSkyline(buildings);
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<", with height:"<<res[i].second<<endl;
	}

}
