class Solution {
public:
    int solve(vector<int>& coins ,int amount ){
        if(amount == 0 ){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        int mini = INT_MAX - 1;

        for(int i = 0 ; i<coins.size() ; i++){
            int ans = solve(coins , amount-coins[i]);
            if(ans!= INT_MAX ){
                mini = min(mini , 1+ ans);
            }
        }
        return mini ; 
    }
    int TopDown(vector<int>& coins, int amount , vector<int> &dp){
        if(amount == 0 ){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        int mini = INT_MAX ;

        for(int i = 0 ; i<coins.size() ; i++){
            int  ans = TopDown(coins , amount-coins[i] , dp);
            if(ans!= INT_MAX ){
                mini = min(mini , 1+ ans);
            }
        }
        dp[amount] = mini ; 
        return dp[amount] ;
    }
    int BottomUp(vector<int>& coins, int amount){
        vector<int > dp(amount+ 1 ,-1 );
        dp[0] = 0;
        int mini = INT_MAX ;
        for(int i = 0 ; i<coins.size() ; i++){
            for(int j= amount ; j>=0 ; j++){
                
            }
        }
        return mini;

    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int > dp(amount+ 1 ,-1 ); 
        // int ans = TopDown(coins, amount , dp);
        int ans = BottomUp(coins,amount);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }

        // ans !=INT_MAX -1 ? ans =  ans : ans = -1 ; 
        // return ans;
    }
};