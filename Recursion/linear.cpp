#include <iostream>
using namespace std;
bool search(int *arr , int size , int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else 
    return search(arr+1,size -1 , key );
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int key= 2;
    int temp = search(arr,5,key);
    if(temp){
        cout<<"element is present";
    }
    else 
    cout<<"not";
}