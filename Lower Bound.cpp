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
int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>x;
	
	int result=LowerBound(arr,n,x);
	cout<<result;
	
	//Method-2  using in-built function
	result=lower_bound(arr,arr+n,x)-arr;
	cout<<result;
}

/*
	arr[7]= 1 2 3 3 5 5 5 
	indeces:0 1 2 3 4 5 6
	
	x=5
	result=4
	
	lowerbound defines the index of first occurrence of an element in a sorted array 
	
	T.C : O(logn)
*/
