#include <iostream>
using namespace std;
int bubblesort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
        
    }
    
}
int print (int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {
        cout<<arr[i];
    }
    
}
int main(){
int arr[5]={6,2,3,4,5};
bubblesort(arr,5);
cout<<print(arr,5);

}