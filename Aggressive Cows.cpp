#include<bits/stdc++.h>
using namespace std;

int calcCows(vector<int>&stalls,int mid){
    int c=1,lastcow=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if((stalls[i]-lastcow)>=mid){
            lastcow=stalls[i];
            c++;
        }
    }
    return c;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    if(stalls.size()<k)
        return -1;
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=*max_element(begin(stalls),end(stalls));
    while(low<=high){
        int mid=low+(high-low)/2;
        int cows=calcCows(stalls,mid);
        if(cows>=k)
            low=mid+1;
        else
            high=mid-1;
    }
    return high;
}

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int>stalls(n);
	for(int i=0;i<n;i++)
		cin>>stalls[i];
	int result=aggressiveCows(stalls,k);
	cout<<result;
}

/*
	You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.
	You are also given an integer 'k' which denotes the number of aggressive cows.
	You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
	Print the maximum possible minimum distance.
	
	Sample Input :
	6 4
	0 3 4 7 10 9

	Sample Output :3
	Explanation :
	The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. 
	Here distance between cows are 3, 4 and 3 respectively.
	
	T.C : O(n*logn)
	
*/

