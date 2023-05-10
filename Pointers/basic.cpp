#include <iostream>
using namespace std;
int main(){
     
     int n=5;
   //  cout<<n<<endl;
//to print the adress
//cout<<"adress of num is "<<&n;
int *ptr=&n;
cout<<"value is :"<<*ptr<<endl;
cout<<"adress is :"<<ptr; 

}