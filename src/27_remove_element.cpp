class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int length=0;
        int pos=0;
        for(int i=0;i<n;i++){
            if(A[i]!=elem){
                A[pos] = A[i];
                pos++;
                length++;
            }
        }
        return length;
    }
};

int main(){

}
