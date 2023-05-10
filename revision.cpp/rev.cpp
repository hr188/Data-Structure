#include <iostream> 
using namespace std;
int main(){
    int x = 1233;
    int a;
    int rev = 0;
    cout<<"chal gaya";
    while(x>=0){
       a = x%10;
       x= x/10;
       rev = rev*10 + a; 
    }
    cout<<"chal gaya";
    cout<<rev;

}