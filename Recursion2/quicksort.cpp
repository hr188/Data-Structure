#include<iostream>
using namespace std;
int partition(int *arr , int s , int e){
    int pivot= arr[s];
    int cnt=0;

    for (int  i = s+ 1; i <=e; i++)
    {
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    //placing pivot at right position
    int pivotindex = s + cnt ;
    swap(arr[pivotindex],arr[s]);

    //left and right ordering 
    int i = s , j = e ;
    if (i <pivotindex && j > pivotindex)
    {
       while (arr[i]<=pivot)
       {
            i++;
       }
       while(arr[j]>=pivot)
       {
        j--;
       }
       if(i <pivotindex && j > pivotindex)
       {
        swap(arr[i++],arr[j--]);
       }
        
    }
    
return pivotindex;
    
}
void quicksort(int *arr , int s , int e){
    if(s>=e){
        return ;
    }
    //partition bna liya 
    
    int p = partition(arr,s,e);
    //left part solve 
    quicksort(arr,s,p-1);
    //right part solve
    quicksort(arr,p+1,e);
}
int main(){
    int arr [12]={2,2,5,4,9,2,1,9,9,9,9,9};
    int n = 12;
    quicksort(arr, 0 , n-1);
    for (int  i = 0; i < n; i++)
    {
       cout<<arr[i]<<endl;;
    }
    
}