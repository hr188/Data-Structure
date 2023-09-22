#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

class Solution {
public:
    int topdown (int n ,vector<int>&dp ){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] =  topdown(n-1,dp) + topdown(n-2,dp);
        return dp[n];

    }
    int bottomUP(int n ){
        if(n<=2) return n;
        vector<int> dp(n+1 ,-1);
        dp[0]=0;
        dp[1] = 1;
        dp[2] = 2;
    
        for(int i=3 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
    int spaceOpt(int n){
        if(n<=2){
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        int curr = 0;
        for(int i =3 ; i<=n ; i++){
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }

    int climbStairs(int n) {
        vector<int>dp(n+1 , -1);
        return spaceOpt(n);
    }
};