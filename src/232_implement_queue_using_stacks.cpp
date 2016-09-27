#include<vector>
#include<string>
#include<iostream>
#include<stack>
using namespace::std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
		stack<int> tmp;
		while(!st.empty()){
			tmp.push(st.top());
			st.pop();
		}
		tmp.push(x);
		while(!tmp.empty()){
			st.push(tmp.top());
			tmp.pop();
		}
    }

    // Removes the element from in front of queue.
    void pop(void) {
		st.pop();
    }

    // Get the front element.
    int peek(void) {
		return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
		return st.empty();
    }
private:
	stack<int> st;
};

int main(){

}
