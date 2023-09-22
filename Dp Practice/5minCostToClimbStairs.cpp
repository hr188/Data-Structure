class Solution {
public:
    
    int rec(vector<int>& cost , int n,vector<int>& dp ){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        

        int oneSkip = rec(cost , n -1 ,dp);
        int twoSkip = rec(cost , n-2 ,dp);

        dp[n] =  min(oneSkip , twoSkip) + cost[n] ;
        return dp[n];
    }
    int BottomUp(vector<int>& cost){
        vector<int>dp(cost.size()+1 , -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int n = cost.size()-1;

        for(int i =2 ; i<=n ; i++ ){
            int oneSkip = dp[i-1];
            int twoSkip = dp[i-2];
            dp[i] =  min(oneSkip , twoSkip) + cost[i] ;
        }
        return min(dp[n] ,dp[n-1]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size()+1 ,-1);
        //  return  min(rec(cost,cost.size()-1,dp) , rec(cost,cost.size()-2 ,dp) );

        return BottomUp(cost);
    }
};class Solution {
public:
    
    int rec(vector<int>& cost , int n,vector<int>& dp ){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        

        int oneSkip = rec(cost , n -1 ,dp);
        int twoSkip = rec(cost , n-2 ,dp);

        dp[n] =  min(oneSkip , twoSkip) + cost[n] ;
        return dp[n];
    }
    int BottomUp(vector<int>& cost){
        vector<int>dp(cost.size()+1 , -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int n = cost.size()-1;

        for(int i =2 ; i<=n ; i++ ){
            int oneSkip = dp[i-1];
            int twoSkip = dp[i-2];
            dp[i] =  min(oneSkip , twoSkip) + cost[i] ;
        }
        return min(dp[n] ,dp[n-1]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size()+1 ,-1);
        //  return  min(rec(cost,cost.size()-1,dp) , rec(cost,cost.size()-2 ,dp) );

        return BottomUp(cost);
    }
};