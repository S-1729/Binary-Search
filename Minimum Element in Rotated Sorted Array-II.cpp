#include<bits/stdc++.h>
using namespace std;
int SearchMinimumElement_II(int arr[],int n)
{
	int low=0,high=n-1,ans=INT_MAX;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[low]<=arr[high])
			ans=min(ans,arr[low]);
		if(arr[low]<=arr[mid] && arr[mid]<=arr[high])
			low++,high--;
		if(arr[low]<=arr[mid])
		{
			ans=min(ans,arr[low]);
			low=mid+1;
		}
		else
		{
			ans=min(ans,arr[mid]);
			high=mid-1;	
		}
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
	
	int result=SearchMinimumElement_II(arr,n);
	cout<<result;
	
}

/*
	arr[7]= 4 5 6 7 1 2 3 //No duplicates
	result=1
	
	arr[7]= 3 1 2 3 3 3 3 //with duplicates
	result=1
	
	Searches for the minimum element in a rotated sorted array with duplicates	 
	
	T.C : O(logn)
*/
