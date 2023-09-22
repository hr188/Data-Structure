class Solution {
public:
    int rec(vector<int>& obs ,int currLane , int currPos , vector< vector<int> > &dp){
        if( currPos== obs.size()-1){
            return 0;
        }
        if(dp[currPos][currLane]!= -1){
            return dp[currPos][currLane];
        }
        

        if(obs[currPos+1] != currLane  ){
           return  dp[currPos][currLane] =  rec(obs,currLane , currPos+1 ,dp);
        }
        else{
            int ans = INT_MAX;
            for(int i = 1 ; i<=3 ; i++){
                if(currLane!= i && obs[currPos]!= i)
                ans  = min(ans , 1+ rec(obs,i , currPos,dp));
            }
            
            return dp[currPos][currLane] = ans;
        }
       
    }
    int Tab (vector<int>& obs ){
        int n = obs.size()-1;
        vector< vector<int> > dp (4, vector<int> (n+1 , 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int pos = n-1 ; pos>=0 ; pos--){
            for(int lane = 1 ; lane<=3 ; lane ++){
                if(  obs[pos+1] != lane  ){
                    dp[lane][pos] =  dp[lane][pos+1 ];
                }
                else{
                    int ans =1e9;
                    for(int i = 1 ; i<=3 ; i++){
                        if(lane!= i && obs[pos]!= i)
                        ans  = min(ans , 1+ dp[i][pos+1]);
                    }
                    
                     dp[lane][pos] = ans;
                }
            }
        }
        return min(dp[2][0] , min(1+ dp[1][0] ,1 +  dp[3][0])) ;
    }
    int minSideJumps(vector<int>& obstacles) {
        
        // vector<vector<int>> dp(obstacles.size() + 1, vector<int>(4, -1));
        // return rec(obstacles , 2, 0 ,dp);
        return Tab(obstacles);
    }
};