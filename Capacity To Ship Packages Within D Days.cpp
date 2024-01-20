#include<bits/stdc++.h>
using namespace std;

long long countDays(vector<int>& weights, int mid)
{
    int noofDays=1,sum=0;
    for(auto i: weights)
    {
        if(sum+i>mid){
            noofDays++;
            sum=i;
        }
        else{
            sum+=i;
        }
    }
    return noofDays;
}

int shipWithinDays(vector<int>& weights, int days) {
    long long low=*max_element(weights.begin(),weights.end());
    long long high=accumulate(weights.begin(),weights.end(),(long long)0);
    while(low<=high)
    {
        long long mid=low+(high-low)/2;
        long long noofDays=countDays(weights,mid);
        if(noofDays>days)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int main()
{
	int n,days;
	cin>>n>>days;
	vector<int>weights(n);
	for(int i=0;i<n;i++)
		cin>>weights[i];
	int result=shipWithinDays(weights,days);
	cout<<result;
}

/*
	A conveyor belt has packages that must be shipped from one port to another within days days.
	The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
	We may not load more weight than the maximum weight capacity of the ship.
	Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
	
	Input: weights = [3,2,2,4,1,4], days = 3
	Output: 6
	Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
	1st day: 3, 2
	2nd day: 2, 4
	3rd day: 1, 4
	
	T.C : O(n*log(arraySum-max_element+1))
*/
