class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int pos=0;
		int curNum=0;
		int length=0;
		for(int i=0;i<n;i++){
			if(A[i]>curNum||i==0){
				A[pos] = A[i];
				pos++;
				curNum = A[i];
				length++;
			}
		}
		return length;
    }
};
int main(){

}
