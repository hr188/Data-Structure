#include <iostream>
using namespace std;
void print(int arr[] , int s , int e){
    for (int  i = s; i < e; i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int  firstmostocc( int arr[], int s , int e , int key){
    print(arr,s,e);
    if(s>e){
        return -1 ;
    }
    
    int mid = s + (e-s)/2;
    int ans=-1;
    if (arr[mid]== key){
        ans=mid;
        e=mid-1; 
    }
    
    if(arr[mid]<key){
        return firstmostocc(arr ,mid +1 , e , key );
    }
    else if (arr[mid]>key){
    return firstmostocc(arr, s ,mid-1, key); 
    }
    else 
    return ans;
}
int  lastmostocc( int arr[], int s , int e , int key){
    print(arr,s,e);
    if(s>e){
        return -1 ;
    }

    int mid = s + (e-s)/2;
    int ans=-1;
    if (arr[mid]== key){
        ans=mid;
        s= mid +1; 
    }
    
    if(arr[mid]<key){
        return lastmostocc(arr ,mid +1 , e , key );
    }
    else if (arr[mid]>key){
    return lastmostocc(arr, s ,mid-1, key); 
    }
    else 
    return ans;
}
int main(){

    int arr [9]={1,2,2,2,4,6,8,9,10};
    int temp = lastmostocc(arr,0,9,2);
    int temp1 = firstmostocc(arr,0,9,2);
    cout<<"lastmostocc"<<temp<<endl<<"firstocc"<<temp1;
}
