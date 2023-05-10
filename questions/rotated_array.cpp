#include <iostream>
#include <vector>
using namespace std;

    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());    
    }

int main(){
int arr[4]={1,7,9,11};
int arr2[4]={0};
}