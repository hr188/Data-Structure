#include <iostream>
using namespace std;
void merge(int *arr , int s , int e ){
     int mid = s + (e-s)/2;
     int len1 = mid - s +1;
     int len2 = e - mid;
     
    
    int *first = new int[len1];
    int *second = new int[len2];
    int mainindex=s;
    //copying values of 1st part
    for (int  i = 0; i < len1; i++)
    {
        first[i]=arr[mainindex++];
    }
    //copying values of 2nd part
    mainindex=mid+1;
    for (int  i = 0; i < len2; i++)
    {
        second[i]=arr[mainindex++];
    }
    
    //merge karde
    int index1=0;
    int index2=0;
    mainindex=s;
    while (index1<len1 && index2 <len2)
    {
        if (first[index1]<second[index2])
        {
            arr[mainindex++]=first[index1++];
        }
        else {
            arr[mainindex++]=second[index2++];
        }
        
    }
    
    while (index1<len1)
    {
        arr[mainindex++]=first[index1++];
    }
    while(index2<len2)
    {
        arr[mainindex++]=second[index2++];
    }
    
    delete []first;
    delete []second;
}
void mergesort(int *arr , int s , int e){
    if(s>=e){
        return;
    }
    int mid = s + (e-s)/2;
    //left
    mergesort(arr , s , mid );
    //right 
    mergesort(arr , mid +1 , e);

    merge (arr, s, e );

    
}
int main(){
    int arr[5]={5,4,3,2,1};
    int n = 5;
    mergesort(arr, 0 , n-1);

    for (int  i = 0; i < n ; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}
