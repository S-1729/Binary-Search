#include<bits/stdc++.h>
using namespace std;

long long minimumTime(vector<int>& time, int totalTrips) {
    long long low=1;
    long long high=(long long)*min_element(time.begin(),time.end())*totalTrips;
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long trips =0;
        for(auto i:time)
            trips+=mid/i;
        if(trips>=totalTrips)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
	int n,totalTrips;
	cin>>n>>totalTrips;
	vector<int>time(n);
	for(int i=0;i<n;i++)
		cin>>time[i];
	int result=minimumTime(time,totalTrips);
	cout<<result;
}

/*
	You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.
	Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
	Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.
	You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
	Return the minimum time required for all buses to complete at least totalTrips trips.
	
	Input: time = [1,2,3], totalTrips = 5
	Output: 3
	Explanation:
	- At time t = 1, the number of trips completed by each bus are [1,0,0]. 
  	  The total number of trips completed is 1 + 0 + 0 = 1.
	- At time t = 2, the number of trips completed by each bus are [2,1,0]. 
  	  The total number of trips completed is 2 + 1 + 0 = 3.
	- At time t = 3, the number of trips completed by each bus are [3,1,1]. 
  	  The total number of trips completed is 3 + 1 + 1 = 5.
	So the minimum time needed for all buses to complete at least 5 trips is 3.
	
	T.C : O(n*log(min_element*totalTrips))
*/
