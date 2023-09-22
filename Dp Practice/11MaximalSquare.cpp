class Solution {
public:
    int maxi =0;
    int rec(vector<vector<char>>& matrix ,int n , int m , int i , int j){
        if(i>=n && j>=m){
            return 0;
        }
        
        int right = rec(matrix,n,m,  i, j+1);
        int diagnol = rec(matrix,n,m, i+1, j+1);
        int down = rec(matrix,n,m, i+1,j);
        
        if(matrix[i][j]=='1'){
            int ans = 1 +  min(right,min(diagnol,down));
            maxi = max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
        
    }
    int Tab(){
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size()  ;
        int m = matrix[0].size()  ;
         int ans = rec(matrix,n,m,0,0);
         return maxi;
    }
};