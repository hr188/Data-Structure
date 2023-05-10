#include <iostream>
using namespace std;
void printsum( int arr[][3],int i , int j){
    
for (int  i = 0; i < 3; i++)
{
    int sum =0;
for (int  j= 0; j < 3; j++)
{
    sum += arr[i][j]; 
    
}
cout<<sum<<" ";

}
}


int largestrowsum (int arr [][3],int i , int j){
    int maxi=INT_MIN;
    int rowindex=-1;
for (int  i = 0; i < 3; i++)
{
    int sum =0;
    
for (int  j= 0; j < 3; j++)
{
    sum += arr[i][j]; 
    
}
if (sum>maxi)
{
    maxi=sum;
    rowindex=i+1;
}

}
cout<<"the maximum sum is "<<maxi;
return rowindex;
}
int main(){
    int arr[3][3];
    cout<<"Enter the elements of the array"<<endl;
for (int  i = 0; i < 3; i++)
{
for (int  j= 0; j < 3; j++)
{
    cin>>arr[i][j];
    
}
}
printsum(arr,3,3);
int max = largestrowsum(arr,3,3);
cout<<"index"<<max;
}