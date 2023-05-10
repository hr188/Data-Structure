#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main(){
    set<int>s;
    
    s.insert(5);
    s.insert(2);
    s.insert(3);
    s.insert(16);
    s.insert(12);
    s.insert(10);
    s.erase(s.begin());
    s.count(5);
   for(auto i:s){

    cout<<i<<endl;
   }


}