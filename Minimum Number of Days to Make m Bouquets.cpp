#include<bits/stdc++.h>
using namespace std;

long long countBouquets(vector<int>& bloomDay, long long n,long long k,long long mid){
    long long numOfBouquets=0,c=0;
    for(auto i:bloomDay){
        if(mid>=i){
            c+=1;
        }
        else{
            numOfBouquets+=c/k;
            c=0;
        }
    }
    numOfBouquets+=c/k;
    return numOfBouquets;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long n=bloomDay.size();
    if((long long)m*(long long)k>n)
        return -1;
        
    long long low=*min_element(bloomDay.begin(),bloomDay.end());
    long long high=*max_element(bloomDay.begin(),bloomDay.end());
    while(low<=high){
        long long mid=low+(high-low)/2;
        long long numOfBouquets=countBouquets(bloomDay,n,k,mid);
        if(numOfBouquets>=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
	return low;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>bloomDay(n);	
	for(int i=0;i<n;i++)
		cin>>bloomDay[i];
	int result=minDays(bloomDay,m,k);
	cout<<result;
}

/*
	You are given an integer array bloomDay, an integer m and an integer k.
	You want to make m bouquets. 
	To make a bouquet, you need to use k adjacent flowers from the garden.
	The garden consists of n flowers, 
	the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
	Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
	If it is impossible to make m bouquets return -1.
	
	Input: n = 9, m = 2, k = 3, bloomDay = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ]
	Output: 3. 
	
	Explanation: This is because on the 3rd day: all the roses with 'bloomDay[i]' less than equal to 3 have already bloomed, 
	this means every rose except the 5th rose has bloomed. 
	Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.

	T.C : O(n*log(max_element-min_element+1))
*/
