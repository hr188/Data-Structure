class Solution {
public:
    int solve (vector<int>& s , int i, int time ,vector<vector<int> >& dp){
        if(i == s.size()){
            return 0;
        }
        if(dp[i][time]!= -1){
            return dp[i][time];
        }
        int include = s[i]* (time+ 1 ) + solve(s,i+1 ,time +1,dp );
        int exclude = 0+ solve(s,i+1,time,dp);
        return dp[i][time] = max(include,exclude);
    }
    int Tab(vector<int>& s){
        int n = s.size()- 1;
        vector<vector<int> > dp(s.size()+ 1 , vector<int> (s.size() +1  ,0 ));

        for(int i = n ; i>=0 ; i-- ){
            for(int time = i ; time>= 0; time --){
                int include = s[i]*(time+1) + dp[i+1][time+1];
                int exclude = dp[i+1][time];
                dp[i][time]= max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int Tab2(vector<int>& s){
        int n = s.size()- 1;
        vector<int> prev(s.size()+ 1 , 0);
        vector<int> curr(s.size() +1 , 0);

        for(int i = n ; i>=0 ; i-- ){
            for(int time = i ; time>= 0; time --){
                int include = s[i]*(time+1) + prev[time+1];
                int exclude = prev[time];
                curr[time]= max(include, exclude);
            }
            prev = curr;
        }
        return curr[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        // sort(satisfaction.begin(),satisfaction.end());
        // // vector<vector<int> > dp(satisfaction.size()+ 1 , vector<int> (satisfaction.size() +1  ,-1));
        // return Tab2(satisfaction );

        int sum = 0, res = 0, score = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for(int i=satisfaction.size()-1; i>=0; i--){
            sum += satisfaction[i];
            score += sum;
            res = max(res, score);
        }
        return res;
    }
};