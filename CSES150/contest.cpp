class Solution {
public:

    void solve  (vector<int>& nums , vector<vector<int>>&ans , vector<int> op,  int i){
        if(i>=nums.size()){
            ans.push_back(op);
            return ;
        }

        solve(nums, ans , op , i+1 );
        op.push_back(nums[i]);
        solve(nums, ans , op , i+1 );
    }


    long long maximumSum(vector<int>& nums) {
        vector<int> arr(nums.size());
        for(int i =0 ; i<nums.size() ; i++){
            arr.push_back(i+1);
        }
        vector<vector<int>> ans;
        vector<int> op;
        int i = 0;

        solve(arr, ans,op,i);
        
       for (auto it = ans.begin(); it != ans.end(); ) {
       int product = 1;
       for (auto el : *it) {
        product *= el;
       }
       int root = sqrt(product);
       if (root * root != product) {
        it = ans.erase(it); // Erase the current element and get the next iterator
        } else {
        ++it; // Move to the next element in the vector
      }
}
  
        
        int maxi = 0;
        for(auto i : ans){
            int sum=0;
            for(auto el : i){
                sum+=el;
            }
            maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};
