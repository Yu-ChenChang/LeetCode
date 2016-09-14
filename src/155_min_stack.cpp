#include<vector>
#include<string>
#include<iostream>
#include<stack>
using namespace::std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
		st.push(x);
		if(minSt.empty() || x<=minSt.top()){
			minSt.push(x);
		}
    }
    
    void pop() {
		int x = st.top();
		st.pop();
		if(x==minSt.top())
			minSt.pop();
        
    }
    
    int top() {
		return st.top();
    }
    
    int getMin() {
		return minSt.top();
    }
private:
	stack<int> st;
	stack<int> minSt;
};

int main(){

}
