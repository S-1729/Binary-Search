#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>&arr,int mid)
{
	int sum=0,c=1;
	for(auto i:arr){
		if(sum+i>mid){
			sum=i;
			c++;
		}
		else
			sum+=i;
	}
	return c;
}

int splitArray(vector<int> &arr, int k) {
	int low=*max_element(arr.begin(),arr.end());
	int high=accumulate(arr.begin(),arr.end(),0);
	while(low<=high){
		int mid=low+(high-low)/2;
		int subarrays=countSubarrays(arr,mid);
		if(subarrays<=k)
			high=mid-1;
		else
			low=mid+1;
	}
	return low;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int result=splitArray(arr,k);
	cout<<result;
}
/*
	Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
	Return the minimized largest sum of the split.
	A subarray is a contiguous part of the array.
	
	Input: nums = [7,2,5,10,8], k = 2
	Output: 18
	Explanation: There are four ways to split nums into two subarrays.
	The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
	
	T.C : O(n*log(arraySum-max_element+1))
*/
