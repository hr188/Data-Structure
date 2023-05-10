#include<iostream>
using namespace std;
bool ispresent(int arr[][4], int target, int row,int col  ){
for (int  i = 0; i < row; i++)
{
for (int  j= 0; j < col; j++)
{
    if(arr[i][j]==target)
    return 1;
}
}
return -1;
}
int main(){
int target , arr[4][3];
cin>>target;
cout<<"Enter elements";
for (int  i = 0; i < 3; i++)
{
for (int  j= 0; j < 4; j++){
    cin>>arr[i][j];
}
}
if(ispresent ){
    cout<<"is present ";
}
else 
cout<<"not";
}