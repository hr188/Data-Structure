#define MOD 1000000007
#include <vector>
long long int rec (int n , vector<int> &dp ){
    if(n==1){
        return 0; 
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }

    long long int   a = rec(n-2,dp) %MOD;
    long long int  b = rec(n-1,dp) %MOD;
    dp[n]= ((n-1)%MOD * (a+b))%MOD;
    return dp[n];
}
long long int Tab(int n ){
    vector<int>dp(n+1 ,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i =3  ; i<=n ; i++){
        long long int   a = dp[i-2] %MOD;
        long long int  b  = dp[i-1]%MOD ;
        dp[i]= ((i-1)%MOD * (a+b))%MOD;
    }
    return dp[n];
}
long long int SpaceOPt(int n ){
    
}
long long int countDerangements(int n) {
    // if(n==1){
    //     return 0; 
    // }
    // if(n==2){
    //     return 1;
    // }

    // long long int   a = countDerangements(n-2) %MOD;
    // long long int  b = countDerangements(n-1) %MOD;
    // return ((n-1)%MOD * (a+b))%MOD;
    vector<int> dp(n+1,-1);
    return Tab(n);
}