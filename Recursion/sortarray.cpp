#include <iostream>
using namespace std;
void sortarray(int *arr , int n ){
    if(n==0 || n==1){
        return ;
    }

    for (int  i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    sortarray(arr,n-1);

}

int main(){
int arr[5]={1,5,2,3,4};

sortarray(arr,5);
 for (int  i = 0; i < 5; i++)
    {
       cout<<arr[i]<<" ";
    }
}