#include <iostream>
using namespace std;
int firstocc(int n, int arr[],int k){
int s=0,e=n-1,m=s+(e-s)/2,temp=-1;
while (s<=e)
{
    if (arr[m]==k)
    {
        temp=m;
        e=m-1;
    }
    else if (arr[m]>k)
    {
      e=m-1;
    }
    else if (arr[m]<k)
    {
        s=m+1;
    }
    m=s+(e-s/2);
}
return temp;

}
int lastocc(int n, int arr[],int k){
int s=0,e=n-1,m=s+(e-s)/2,temp=-1;
while (s<=e)
{
    if (arr[m]==k)
    {
        temp=m;
        s=m+1;
    }
    else if (arr[m]>k)
    {
      e=m-1;
    }
    else if (arr[m]<k)
    {
        s=m+1;
    }
    m=s+(e-s/2);
}
return temp;

}

int main(){
int arr[6]={1,2,3,3,4,5};

cout<<"first and last occurence is :"<<firstocc(6,arr,4)<<endl<<lastocc(6,arr,4);
}