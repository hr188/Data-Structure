#include <iostream>
#include <vector>
using namespace std;
int main(){

vector <int> h;
cout<<h.size()<< " "<<h.capacity()<<endl;
h.push_back(10);
h.push_back(20);
h.push_back(45);
cout<<h.size()<< " "<<h.capacity()<<endl;

for(auto i : h){
    cout<<i <<" ";
}
}