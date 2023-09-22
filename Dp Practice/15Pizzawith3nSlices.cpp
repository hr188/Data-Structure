class Solution {
public:
    
    int rec(int i  , vector<int>& slices , int n,vector<vector<int>>& dp ){
        if(n==0 || i>= slices.size()){ 
            return 0;
        }
        if(dp[i][n]!= -1){
            return dp[i][n];
        }
        int take = slices[i] + rec(i+2,slices,n-1,dp);
        int notTake = 0 + rec(i+1 , slices , n,dp);

        return dp[i][n] =  max(take,notTake);
    }
    
    int Tab (vector<int>& slices){
        int n = slices.size();
        int k = n/3;
        vector<vector<int>> dp(n+2 ,vector<int>(n+2, 0) );
        vector<vector<int>> dp2(n+2 ,vector<int>(n+2, 0) );

        for(int i = n-2 ; i>= 0 ; i--){
            for(int j = 1 ; j<=k; j++){
                int take = slices[i] +  dp[i+2][j-1]; 
                int notTake = 0 + dp[i+1][j];
                dp[i][j] = max(take,notTake);
            }
        }
        int case1 =  dp[0][k];

        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = 1 ; j<=k; j++){
                int take = slices[i] +  dp2[i+2][j-1]; 
                int notTake = 0 + dp2[i+1][j];
                dp2[i][j] = max(take,notTake);
            }
        }
        int case2 =  dp2[1][k];

        return max(case1, case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        
        // int k= slices.size();
        // vector<vector<int> >dp (slices.size() + 1 , vector<int>((k/3)+ 1  , -1) );
        // int n = rec(0,slices,k/3 ,dp);
        // int m = rec(1,slices,k/3 , dp);
        // return max(n,m);
        return Tab(slices);
    }
};