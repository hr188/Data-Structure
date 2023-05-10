#include <iostream>
using namespace std;
int selection (int arr[],int n){
for (int i = 0; i < n-1; i++)
{
    int min=i;
    for (int j =i+1; j < n ;j++)
    {
        if(arr[j]<arr[min])
        min=j;
    }
    swap(arr[min],arr[i]);
}
}
int print (int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {
        cout<<arr[i];
    }
}  
int main(){
int arr[5]={5,4,3,2,1};
selection(arr,5);
cout<< print(arr,5)<<endl;



}