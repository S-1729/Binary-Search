#include<bits/stdc++.h>
using namespace std;

long long repairCars(vector<int>& ranks, int cars) {
    long long low=1,high=1e14;
    while(low<=high)
    {
        long long mid=low+(high-low)/2;
        long long noofCars=0;
    	for(auto i:ranks)
        	noofCars+=sqrt(mid/i);
        if(noofCars>=cars)
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}

int main()
{
	int n,cars;
	cin>>n>>cars;
	vector<int>ranks(n);
	for(int i=0;i<n;i++)
		cin>>ranks[i];
	int result=repairCars(ranks,cars);
	cout<<result;
}

/*
	You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. 
	A mechanic with a rank r can repair n cars in r * n2 minutes.
	You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
	Return the minimum time taken to repair all the cars.
	Note: All the mechanics can repair the cars simultaneously.
	
	Input: ranks = [4,2,3,1], cars = 10
	Output: 16
	Explanation: 
	- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
	- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
	- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
	- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
	It can be proved that the cars cannot be repaired in less than 16 minutes.?????
	
	T.C : O(n*log(1e14))
	
*/
