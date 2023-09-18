class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        // excluding last element
        int prev1 = nums[0], prev2 = 0;
        for(int i = 1; i<n-1; i++){
            int temp = prev2;
            prev2 = max(prev1,prev2);
            prev1 = nums[i] + temp;
        }
        int first = max(prev1, prev2);
        
        //excluding first element
        prev1 = nums[1], prev2 = 0;
        for(int i = 2; i<n; i++){
            int temp = prev2;
            prev2 = max(prev1,prev2);
            prev1 = nums[i] + temp;
        }
        int last = max(prev1, prev2);
        
        //returning the max of first and last
        return max(first, last);
    }
};