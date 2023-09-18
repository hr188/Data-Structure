#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
class Solution{
    public:
    const int mod = 1000000007;
    long long solve(int n, int k , vector<long long>& dp){
        
        if(n==1){
            return k;
        }
        if(n==2){
            return k*k;
        }
        if(dp[n] != -1){
            return dp[n];
        }
              
        dp[n] = (solve(n - 2, k, dp) + solve(n - 1, k, dp)) * (k - 1) %mod;
        return dp[n];
    }
    
    long long tab (int n , int k ){
        vector<long long>dp(n+1 , -1);
        dp[1]= k;
        dp[2]= k*k;
        
        for(int i = 3 ; i<= n ; i++ ){
            dp[i] = ((dp[i-2] + dp[i-1]) *(k-1)) % mod;
        }
        return dp[n];
    }
    long long countWays(int n, int k){
        
        return tab(n,k) % mod;
    }
};