//increasing order
#include <iostream>
using namespace std;
#define ll long long 
int main(){
    int n ;
    cin>>n ;
    int maxi = 0;
    ll sum = 0;

    for(int i =0 ; i< n ; i++){
        int a;
        cin>>a ;
        maxi = max(maxi,a);
        sum += maxi -a;
    }
    cout<<sum;
}

