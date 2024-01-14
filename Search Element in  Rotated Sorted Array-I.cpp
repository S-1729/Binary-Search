#include<bits/stdc++.h>
using namespace std;
int SearchRotatedArray_I(int arr[],int n,int x)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==x)
			return mid;
		else if(arr[low]<=arr[mid])
		{
			if(arr[low]<=x && x<=arr[mid])
				high=mid-1;
			else
				low=mid+1;
		}
		else
		{
			if(arr[mid]<=x && x<=arr[high])
				low=mid+1;
			else
				high=mid-1;	
		}
	}
	return -1;
}
int main()
{
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>x;
	
	int result=SearchRotatedArray_I(arr,n,x);
	cout<<result;
	
}

/*
	arr[7]= 4 5 6 7 1 2 3 //No duplicates
	indices:0 1 2 3 4 5 6
	
	x=1
	result=4
	
	x=0
	result=-1
	
	Searches for the index of an element in a rotated sorted array with no duplicates
	 
	
	T.C : O(logn)
*/
