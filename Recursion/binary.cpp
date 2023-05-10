#include <iostream>
using namespace std;
bool search ( int arr[], int s , int e , int key){
    if(s>e){
        return false ;
    }

    int mid = s + (e-s)/2;
    if (arr[mid]== key){
        return true;
    }

    if(arr[mid]<key){
        return search(arr ,mid +1 , e , key );
    }
    else 
    return search(arr, s ,mid-1, key); 
}

int main() {
    int arr [5]= {1,2,3,4,5};
    int key = 3;

    int temp = search(arr, 0 ,4 , 3);
    if(temp){
        cout<<"element is present ";
    }
    else 
    cout<<"not";
}