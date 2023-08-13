#include <iostream>
using namespace std;
#define ll long long
int main(){
    ll  n ;
    cin>>n ;

    ll sum = 0;
    for(int i =1 ; i<n ;i++){
        int a; 
        cin>>a ;
        sum += a;
    }
    cout<<n*(n+1)/2 - sum;

}