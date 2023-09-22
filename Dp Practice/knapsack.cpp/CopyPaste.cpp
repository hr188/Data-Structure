#include <iostream>
#include <algorithm>
using namespace std;
int dp[100][100];
int rec(int n , int w[] , int val[], int W ){
    if(n==0 || w==0){
        return 0;
    }
    //n-1 because we are starting from arr.size()
    if(w[n-1]<= W){
        return max(val[n-1] + rec(n-1,w,val,W-w[n-1]), rec(n-1,w,val,W)); 
    }
    else if(w[n-1]>W){
        return rec(n-1,w,val,W);
    }

}

int TopDown(int n , int w[] , int val[], int W){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][W]!= -1 ){
        return dp[n][W];
    }

    //n-1 because we are starting from arr.size()
    if(w[n-1]<= W){
        return dp[n][W] =  max(val[n-1] + TopDown(n-1,w,val,W-w[n-1]), TopDown(n-1,w,val,W)); 
    }
    else if(w[n-1]>W){
        return dp[n][W] =  TopDown(n-1,w,val,W);
    }
}
int Tab(int n , int w[] , int val[], int W){

    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=W ; j++){
            if(w[i-1] <=j){
                dp[i][j] = max(val[i-1]+ dp[i-1][j-w[i-1]], dp[i-1][j]);
            }
            else if(w[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main(){
int n = 5;
int w[] = {1,2,3,4,5};
int val[]= {1,5,9,2,3};
int W = 10;
//int ans = TopDown(n,w,val,W);
//cout<<ans;
//tab
for(int i =0 ; i<=n ; i++){
    for(int j =0 ; j<=W ; j++ ){
        if(i==0 || j==0){
            dp[i][j] = 0;
        }
    }
}

int ans = Tab(n,w,val,W);
cout <<ans;

}