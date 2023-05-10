//leetcode merge sort
#include <iostream>
using namespace std;

void merge(vector<int>& nums , int s , int e ){
     int mid = s + (e-s)/2;
     int len1 = mid - s +1;
     int len2 = e - mid;
     
    
    int *first = new int[len1];
    int *second = new int[len2];
    int mainindex=s;
    //copying values of 1st part
    for (int  i = 0; i < len1; i++)
    {
        first[i]=nums[mainindex++];
    }
    //copying values of 2nd part
    mainindex=mid+1;
    for (int  i = 0; i < len2; i++)
    {
        second[i]=nums[mainindex++];
    }
    
    //merge karde
    int index1=0;
    int index2=0;
    mainindex=s;
    while (index1<len1 && index2 <len2)
    {
        if (first[index1]<second[index2])
        {
            nums[mainindex++]=first[index1++];
        }
        else {
            nums[mainindex++]=second[index2++];
        }
        
    }
    while (index1<len1)
    {
        nums[mainindex++]=first[index1++];
    }
    while(index2<len2)
    {
        nums[mainindex++]=second[index2++];
    }
    
    delete []first;
    delete []second;
}
void mergesort(vector<int>& nums , int s , int e){
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    //left
    mergesort(nums , s , mid );
    //right 
    mergesort(nums , mid +1 , e);

    merge (nums, s, e );

    
}
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0 ,nums.size()-1);
        return nums;
    }
