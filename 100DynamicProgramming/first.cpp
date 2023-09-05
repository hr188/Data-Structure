#include <iostream> 
#include <vector>
using namespace std;    
int fib(int n , vector<int> &dp ){
    if(n==0 || n==1) return n;

    if(dp[n]!=0) return dp[n];
    
    dp[n] = fib(n-1 , dp) + fib(n-2 , dp);
    return dp[n];
}
int BottomUp(int n ){
        //step 1 create a dp array 
        vector<int>dp (n+1 , -1);
        //step 2 observe base case in above solution
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i<=n ; i++){
            dp[i] = dp[i-1] + dp[i-2]; 
        }
        return dp[n];
    }
int main(){
    int n = 8;
    vector<int> dp(n+1,0);
    cout<< fib(n,dp);
  
    return 0;
}