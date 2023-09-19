class Solution {
public:
    int rec(int n  , vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!= -1){
            return dp[n];
        }
       
        int mini = n;
        for(int i = 1 ; i*i <=n ; i++){
            int ans = rec(n- i*i , dp) ;
            mini = min(mini , ans+1);
        }
        dp[n] =  mini;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1 , -1);
        return rec(n,dp);
    }
};