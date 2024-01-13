#include<bits/stdc++.h>
using namespace std;
int LowerBound(int arr[],int n,int x)
{
	int low=0,high=n-1,ans=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]>=x){
			ans=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return ans;
}

int UpperBound(int arr[],int n,int x)
{
	int low=0,high=n-1,ans=n;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else
			low=mid+1;
	}
	return ans;
}
int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>x;
	
	int lb=LowerBound(arr,n,x);
	int ub=UpperBound(arr,n,x);
	cout<<(ub-lb);
}

/*
	arr[7]= 1 2 3 3 5 5 5 
	indices:0 1 2 3 4 5 6
	
	x=3
	lower_bound=2
	upper_bound=4
	result=upper_bound-lower_bound
		  =2
	
	T.C : O(2*logn)
*/
