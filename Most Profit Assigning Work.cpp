class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>arr;
        for(int i=0;i<profit.size();i++)
            arr.push_back({difficulty[i],profit[i]});
        sort(begin(arr),end(arr));
        
        for(int i=1;i<profit.size();i++)
            arr[i].second=max(arr[i].second,arr[i-1].second);
        
        int ans=0;
        for(auto ele:worker){
            int low=0,high=profit.size()-1,maxProfit=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[mid].first<=ele){
                    maxProfit=max(maxProfit,arr[mid].second);
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
            ans+=maxProfit;
        }
        return ans;
    }
};

/*
    You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
      .difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
      .worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
    Every worker can be assigned at most one job, but one job can be completed multiple times.
      .For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
    Return the maximum profit we can achieve after assigning the workers to the jobs.
    
    Example 1:
    Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
    Output: 100
    Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
    
    Example 2:
    Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
    Output: 0

    T.C : O(nlogn)
    S.C : O(n)
*/
