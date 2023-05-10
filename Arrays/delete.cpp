#include <iostream>
using namespace std; 
void deletee(int*arr , int& n , int key){
    for (int i = 0; i < n ; i++)
    {
        if(arr[i]==key){
            for (int  j = i; j < n-1 ; j++)
            {
               arr[j]=arr[j+1];
            }
            n--;
            i--;
        }
        
    }
    
}
int main(){
int arr [9]={5,3,2,4,1,5,5,5,5};
int n = 9;
deletee(arr,n,5);

for (int i = 0; i < n; i++)
{
   cout<<arr[i];
}


}