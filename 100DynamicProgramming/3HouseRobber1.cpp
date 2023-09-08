#include <iostream>
using namespace std;
int recursion(vector<int>nums , int n ){
    if(n < 0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    int include = recursion(nums, n-2) + nums[n];
    int exclude = recursion(nums, n-1);

    return max(include,exclude);
}
int TopDown(vector<int>&nums , int n , vector<int> &dp){
    if(n < 0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    if(dp[n]!= -1){
        return dp[n];
    }

    int include = recursion(nums, n-2) + nums[n];
    int exclude = recursion(nums, n-1);

    dp[n] = max(include,exclude);
    return dp[n];
}
int BottonUp(vector<int>&nums , int n ){
    vector<int>dp(n+1 ,0);
    dp[0] = nums[0];

    for(int i = 1  ; i<=n ; i++){
        int temp = 0 ;
        if(i-2>= 0) temp = dp[i-2];

        int include = temp  + dp[i];
        int exclude = dp[n-1];
        
        dp[i] = max(include , exclude);
    }
    return dp[n];

}
int  SpaceOpt(vector<int>&nums , int n){
    int prev2= 0;
    int prev1 = nums[0];
    int curr = 0;

    for(int i =1 ; i<=n ; i++){
        int temp = 0 ;
        if(i-2>=0) temp = prev2;

        int include= temp + nums[i];
        int exclude = prev1 ; 
        curr = max(include , exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main(){
    //int n = 3;
    //vector<int> dp(n+1 , -1);

    vector<int> nums(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    cout<<nums.size()<<endl;
   cout<< SpaceOpt(nums,nums.size()-1);

}