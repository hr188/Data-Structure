#include <iostream>
using namespace std;
bool isprime(int n){
if(n<=1){
    return false;
}
for (int  i = 2; i < n ; i++)
{
    if(i%n==0){
        return false;
    }
}
return true;
}

int main(){
    int n;
cin >> n;
if (isprime(n)){
    cout<<"is prime "<<endl;
}
else 
cout<<"not";

}