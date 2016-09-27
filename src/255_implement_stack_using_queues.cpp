#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace::std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> tmp;
		tmp.push(x);
		while(!que.empty()){
			tmp.push(que.front());
			que.pop();
		}
		que = tmp;
    }

    // Removes the element on top of the stack.
    void pop() {
       	que.pop(); 
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
	queue<int> que;
};

int main(){

}
