#include <iostream>
using namespace std;
void merge(int*arr , int s , int e){
int mid = s +(e-s)/2;
int len1=mid-s+1;
int len2=e-mid;

    int *first = new int[len1];
    int *second = new int[len2]; 

    //for first array
    int mainarr =s;
    for (int i = 0; i < len1 ; i++)
    {
        first [i]= arr[mainarr++];
    }
    //for second array
    mainarr =mid +1;
    for (int i = 0; i < len2 ; i++)
    {
        second [i]= arr[mainarr++];
    }

    //merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainarr = s;
    while(index1< len1 && index2 < len2)
    {
        if (first[index1]< second[index2])
        {
            arr[mainarr++]=first[index1++];
        }
        else {
            arr[mainarr++]=second[index2++];
        }
        
    }
    while(index1 <len1){
        arr[mainarr++]=first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainarr++]=second[index2++];
    }



    delete []first;
    delete []second;
    

}
void mergesort(int *arr , int s , int e){

    if (s>=e){
        return;
    }
int mid = s +(e-s)/2;
//left part ke liye
    mergesort(arr,s,mid);
//right part ke liye
    mergesort(arr,mid+1,e);
    
    merge(arr,s,e);
}
int main(){
    int arr [5]={5,4,9,2,1};
    int n = 5;
    mergesort(arr, 0 , n-1);
    for (int  i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;;
    }
    
}