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
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int i=0;
		while(i<intervals.size())
		{
			if(newInterval.start>intervals[i].end)
			{
				res.push_back(intervals[i++]);
			}else if(newInterval.end<intervals[i].start)
			{
				break;
			}else
			{
				newInterval.start = min(newInterval.start,intervals[i].start);
				newInterval.end = max(newInterval.end,intervals[i].end);
				i++;
			}
		}
		res.push_back(newInterval);
		while(i<intervals.size()) res.push_back(intervals[i++]);
		return res;
    }
};

int main(){
	Solution sol;
	Interval in1(1,5);
	vector<Interval> intervals;
	intervals.push_back(in1);
	vector<Interval> res = sol.insert(intervals,Interval(0,0));
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
}
