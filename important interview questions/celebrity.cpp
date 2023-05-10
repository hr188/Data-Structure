// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution 
{
    private:
            bool knows(vector<vector<int> >& M , int a , int b ){
                if(M[a][b]==1)
                return true;
                else 
                return false;
            }
    public:
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int>s;
       //first step mai sare elements dal liye
       for(int i= 0 ; i<n ; i++){
           s.push(n);
       }
       //dusre step mai potential candidate nikalenge
       while(s.size() >1){
           int a = s.top();
           s.pop();
           
           int b = s.top();
           s.pop();
           
           if(knows(M,a,b)){
               s.push(b);
           }
           else{
               s.push(a);
           }
       }
       //step 3 single element in stack is potential celebrity
       //check karlo
       int candidate = s.top();
       
       int zerocount= 0;
       bool rowcheck = 0;
       for(int i = 0 ; i<n ; i++){
           if(M[candidate][i]==0){
               zerocount++;
           }
       }
       if(zerocount==n){
               rowcheck = true;
           }
        //column check 
        bool colcheck=false;
        int onecount = 0;
        for(int i = 0 ; i < n ; i++){
            if(M[i][candidate]==1){
                onecount++;
            }
        }
        if(onecount== n-1){
            return true;
        }
        if(rowcheck== true && colcheck == true ){
            return candidate;
        }
        else{
            return -1;
        }
    }
};
int main(){

}