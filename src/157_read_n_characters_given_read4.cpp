#include<vector>
#include<string>
#include<iostream>
using namespace::std;

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
		    int read = min(read4(buf+res),n);
		    if(!read) break;
		    res += read;
		    n -= read;
		}
		return res;
    }
};

int main(){

}
