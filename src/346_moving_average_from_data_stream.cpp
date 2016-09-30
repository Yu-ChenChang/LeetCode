#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace::std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
		m_maxsize = size;
		sum = 0;
    }
    
    double next(int val) {
		if(que.size()==m_maxsize){
			sum -= que.front();
			que.pop();
		}
		que.push(val);
		sum += val;
		return (double)sum/que.size();
    }
private:
	queue<int> que;
	int m_maxsize;
	int sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(){

}
