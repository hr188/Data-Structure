#include <iostream>
using namespace std;
int firstOccurance(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int mid = (s+e)/2;
    int ans = -1;

    while(s<=e){
        if(arr[mid]== key){
        ans = mid;
        e = mid-1;            
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else if(arr[mid]<key){
            s =mid+1;
        }
        mid = (s+e)/2;
    }
    return ans;
}
int lastOccurance(int arr[], int n, int w){
    int s=0;
    int e =n-1;
    int mid = (s+e)/2;
    int ans = -1;
    while(s<=e){
        if(arr[mid] == w){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]>w){
            e = mid-1;
        }
        else if(arr[mid]< w){
            s = mid + 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}
int main()
{
    int arr[6]={1,2,3,12,12,12};
    cout << "First occurance index is " << firstOccurance(arr, 6, 12) << endl;
    cout << "last occurance index is " << lastOccurance(arr, 6, 12) << endl;
    int n;
        int m,q;
        m = lastOccurance(arr,6,12);
        q = firstOccurance(arr,6,12);
        int total_occurance = (m-q) + 1;
        cout << endl;
        cout << total_occurance << endl;
    return 0;
}

