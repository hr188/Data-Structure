#include<iostream>
using namespace std;
int main(){
//creating  a dynamic 2d array
int row;
int col;
cin>>row;
int **arr=new int*[row];
int *size= new int [row];
for (int i = 0; i < row; i++)
{
    cout<<"Enter the value in"<<i+1<<"array"<<endl;
   cin>>size[i];
   arr[i]=new int [size[i]];
}
//taking input in this array
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < size[i]; j++)
    {
       cin>>arr[i][j];
    }
    
}
//output

for (int i = 0; i < row; i++)
{
    for (int j = 0; j < size[i]; j++)
    {
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
//memory free
for (int i = 0; i < row; i++)
{
    delete []arr[i];
}
delete []arr;
delete []size;


}