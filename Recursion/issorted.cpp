#include <iostream>
using namespace std;
bool isSorted (int arr[], int size ){
if(size==0 || size==1)
return true;
if (arr[0] >arr[1])
{
    return false;
}
else 
return isSorted (arr+1 , size -1);


}
int main(){
   int arr[5]={1,2,4,3,5};
   cout<< isSorted(arr,5);


}