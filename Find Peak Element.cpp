#include<bits/stdc++.h>
using namespace std;

int findPeakElement(int n,int arr[])
{
	if(n==1)
		return arr[0];
	if(arr[0]>arr[1])
	 	return arr[0];
	if(arr[n-1]>arr[n-2])
		return arr[n-1];
		
	int low=1,high=n-2;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
			return arr[mid];
		else if(arr[mid]>arr[mid-1])
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int result=findPeakElement(n,arr);
	cout<<result;
	
}

/*
	arr[]= 1 2 3 4 2 1	
	result=4
	
	arr[]= 1 2 3 4 5
	result=5
	
	arr[]= 5 4 3 2 1
	result=5

	
	finds the Peak element
	
	T.C : O(logn)
*/
