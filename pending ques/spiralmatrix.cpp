#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>ans;

        int count=0;
        int total = row*col;

        int startingrow =0;
        int endingrow= row -1;
        int startingcol=0;
        int endingcol= col-1;
     
        while(count < total){
            //pheli row print 
            for(int index = startingcol ;count < total&& index<=endingcol; index++){
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;
        //ending column print
        for(int index= startingrow ;count < total &&  index<=endingrow ; index++){
            ans.push_back(matrix[index][endingcol]);
            count++;
        }
        endingcol--;
        //printing last row
        for(int index= endingcol ;count < total &&  endingcol>=startingcol; endingrow--){
            ans.push_back(matrix[endingrow][index]);
            count++;
        }
        endingrow--;
        //printing starting col
        for(int index= endingrow ;count < total && endingrow>=startingrow; endingrow--){
            ans.push_back(matrix[index][startingcol]);
            count++;
        }
        startingcol++;
        }
return ans;
    }
};