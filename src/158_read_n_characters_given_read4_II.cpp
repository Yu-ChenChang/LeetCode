#include<vector>
#include<string>
#include<iostream>
#include<queue>
using namespace::std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
		int res=0;
		while(n>0){
			if(!que.empty()){
				buf[res] = que.front();
				que.pop();
				n--;
				res++;
			}
			else{
				int readN = read4(buf+res);
				if(readN>n){
					for(int i=n;i<readN;i++){
						que.push(buf[res+i]);
					}
					readN = n;
				}
				if(!readN) break;
				res += readN;
				n -= readN;
			}
		}
		return res;
    }
private:
	queue<char> que;
};

int main(){

}
