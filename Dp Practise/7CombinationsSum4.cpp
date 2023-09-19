class Solution {
public:
    int rec(vector<int>& nums, int target, vector<int>& dp){
        if(target==0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        
        int ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
             ans += rec(nums,target-nums[i] ,dp);
        }
        dp[target] =  ans;
        return ans;
    }
    int Tab(vector<int>& nums, int target){
        vector<unsigned > dp (target+1 , 0);
        dp[0] = 1;
        for(int i = 1 ; i<= target; i++){
            for(int j = 0 ; j< nums.size() ; j++){
                if(i-nums[j]>=0 ){
                    dp[i]+= dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1 ,-1);
        // return rec(nums,target,dp);
        return Tab(nums,target);

    }
};