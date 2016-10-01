#include<vector>
#include<string>
#include<iostream>
#include<unordered_set>
#include<queue>
#include<utility>
using namespace::std;
/**
 * Definition for an interval.
 **/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
struct compare{
	bool operator()(Interval& l, Interval& r) const{
		if(l.start==r.start){
			return l.end<r.end;
		}
		else{
			return l.start<r.start;
		}

	}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(),intervals.end(),compare());
		vector<Interval> res;
		Interval cur = intervals[0];
		for(int i=1;i<intervals.size();i++){
			if(intervals[i].start<=cur.end){
				cur.end = max(cur.end,intervals[i].end);
			}
			else{
				res.push_back(cur);
				cur = intervals[i];
			}
		}
		res.push_back(cur);
		return res;
    }
};
int main(){
	Solution sol;
}
