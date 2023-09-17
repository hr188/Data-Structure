#include <iostream>
using namespace std;
int  add(int n , int &sum  ){
    if(n<=0){
        return sum;
    }
    int a = n%10;
    n= n/10;
    sum = sum + a;
   return  add(n,sum);

}
int main(){
    int summ = 0;
    int ans = add(123,summ);
    cout<<ans;
}