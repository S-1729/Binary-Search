#include<bits/stdc++.h>
using namespace std;

long long calculateHours(vector<int>& piles, int n,int mid)
{
    long long hours=0;
    for(auto i:piles){
    	hours+= ceil((double)i/(double)mid);
    }
    return hours;
}

int minEatingSpeed(vector<int>& piles, int h)
{
    int n=piles.size();
    long long high=*max_element(piles.begin(),piles.end()),low=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        long long hours=calculateHours(piles,n,mid);
        if(hours<=h)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
	int n,h;
	cin>>n;
	vector<int>piles(n);
	for(int i=0;i<n;i++)
		cin>>piles[i];
	cin>>h;
	
	int result=minEatingSpeed(piles,h);
	cout<<result;
		
}

/*
	Finding the minimum number of bananas ‘m’ to eat per hour so that 
	the monkey can eat all the bananas within ‘h’ hours.

	Input: n = 4, h = 8, piles = [7, 15, 6, 3]
	Output: 5
	
	Explanation: If ‘m’ = 5, then 
	The time taken to empty the 1st pile is 2 hour.
	The time taken to empty the 2nd pile is 3 hour.
	The time taken to empty the 3rd pile is 2 hour.
	The time taken to empty the 4th pile is 1 hour.
	Therefore a total of 8 hours is taken. 
	It can be shown that if the rate of eating bananas is reduced, 
	they can’t be eaten in 8 hours.
	
	T.C : O(n*log(max_element))
	
*/
