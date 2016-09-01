#include<iostream>
#include<string>
#include<vector>
#include<queue>
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
	bool operator()(Interval& lhs, Interval& rhs) const
	{
		return lhs.start<rhs.start;
	}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		if(intervals.empty()) return vector<Interval>();
		sort(intervals.begin(),intervals.end(),compare());
		vector<Interval> res(1,intervals[0]);
		for(int i=1;i<intervals.size();i++)
		{
			if(intervals[i].start<=res.back().end)
			{
				if(intervals[i].end>res.back().end)
				{
					Interval combined(res.back().start, intervals[i].end);
					res.pop_back();
					res.push_back(combined);
				}
			}else
				res.push_back(intervals[i]);
			
		}
		return res;
    }
};

int main(){
	Solution sol;
	Interval in1(2,3);
	Interval in2(3,3);
	Interval in3(1,3);
	Interval in4(15,18);
	vector<Interval> intervals;
	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);
	intervals.push_back(in4);
	vector<Interval> res = sol.merge(intervals);
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}
