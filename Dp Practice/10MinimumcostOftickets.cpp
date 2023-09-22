class Solution {
public:
    int rec(vector<int>& days, vector<int>& costs ,int n , int index , vector<int> &dp){
        if(index >= n){
            return  0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int a = rec(days,costs,n,index+1 ,dp) +costs[0];

        int i;
        for( i = index ; i< n && days[i]< days[index] +7  ; i++ );
        int b = rec(days,costs,n ,i,dp) +costs[1];


        for( i = index ; i< n && days[i]< days[index] + 30 ; i++ );
        int c = rec(days,costs, n , i,dp) +costs[2]; 


        dp[index] =  min(a,min(b,c));
        return dp[index];
    }
    int Tab(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1 ,-1);
        dp[n] = 0;
        for(int k = n-1 ; k>=0 ; k--){
            int a = dp[k+1] +costs[0];

            int i;
            for( i = k ; i< n && days[i]< days[k] +7  ; i++ );
            int b = dp[i] +costs[1];


            for( i = k ; i< n && days[i]< days[k] + 30 ; i++ );
            int c = dp[i] +costs[2]; 

            dp[k] = min(a,min(b,c));
        }
        return dp[0];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int> dp(days.size()+2,-1);
        // return rec(days,costs,days.size() , 0 ,dp);
        return Tab(days,costs);

    }
};