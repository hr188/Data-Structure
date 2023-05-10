#include <iostream>
using namespace std;
int fib(int n ){
    if(n<=1) return n;

    return fib(n-1) + fib(n-2);
}
int main()
{
    int n = 10;
    // int  ans = fib (n);
    // cout<< ans; 
    int ans = 0;
    int first = 0, second=1;
    for (int i = 0 ; i< n ; i++){
        if(i <=1 ){
            cout << i<< endl;
        }
        ans = first + second;
        first = second;
        second = ans;
        cout<<ans<<endl;
    }
}