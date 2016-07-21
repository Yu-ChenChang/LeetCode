#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;
class Solution {
public:
	double findKelement(int* A,int n,int* B, int m,int k){
		if(n==0||m==0) return m==0?A[k-1]:B[k-1];
		else if(k==1) return A[0]<B[0]?A[0]:B[0];
		int nM = (n-1)/2;
		int mM = (m-1)/2;	
		
		if(A[nM]<=B[mM])
		{
			if(nM+1+mM+1<=k)
			{
				return findKelement(A+nM+1,n-nM-1,B,m,k-nM-1);
			}
			else 
				return findKelement(A,n,B,mM,k);
		}
		else
		{
			if(nM+1+mM+1<=k)
			{
				return findKelement(A,n,B+mM+1,m-mM-1,k-mM-1);
			}
			else
				return findKelement(A,nM,B,m,k);
		}	
			
	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		int k = (size1+size2)/2+1;
		if((size1+size2)%2)
			return findKelement(&nums1[0],size1,&nums2[0],size2,k);
		else
			return (findKelement(&nums1[0],size1,&nums2[0],size2,k-1)+
					findKelement(&nums1[0],size1,&nums2[0],size2,k))/2;
    }
	double findMedianSortedArrays(int A[], int m, int B[], int n) 
	{
		if((m+n)%2 == 0)
			return (findKelement(A,m,B,n,(m+n)/2)+findKelement(A,m,B,n,(m+n)/2+1))/2;
		else
			return findKelement(A,m,B,n,(m+n+1)/2);
	}
};

int main(){

	int A[6] = {0,2,4,6,8,10};
	int B[7] = {1,3,5,7,9,11,13};
	Solution s;
	cout<<"Sould be 6: "<<s.findMedianSortedArrays(A,6,B,7)<<endl;
	int C[3] = {1,1,1};
	int D[3] = {1,1,1};
	cout<<"Sould be 1: "<<s.findMedianSortedArrays(C,3,D,3)<<endl;
	int E[1] = {3};
	int F[3] = {1,2,4};
	cout<<"Sould be 2.5: "<<s.findMedianSortedArrays(E,1,F,3)<<endl;
	int G[1] = {0};
	int H[1] = {1};
	cout<<"Sould be 1: "<<s.findMedianSortedArrays(G,0,H,1)<<endl;
	int I[2] = {1,2};
	int J[3] = {3,4,5};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(I,2,J,3)<<endl;
	int K[2] = {4,5};
	int L[3] = {1,2,3};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(K,2,L,3)<<endl;
	int M[1] = {1};
	int N[4] = {2,3,4,5};	
	cout<<"Sould be 3: "<<s.findMedianSortedArrays(M,1,N,4)<<endl;
	int O[2] = {5,6};
	int P[4] = {1,2,3,4};
	cout<<"Sould be 3.5: "<<s.findMedianSortedArrays(O,2,P,4)<<endl;
	int Q[3] = {1,2,3};
	int R[4] = {4,5,6,7};
	cout<<"Sould be 4: "<<s.findMedianSortedArrays(Q,3,R,4)<<endl;
}
