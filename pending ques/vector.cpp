#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(100);
    v.push_back(2);
    v.push_back(8);
    v.push_back(1233);

    sort(v.begin(), v.end(),greater<int>());
    


    for(auto  i : v){
        cout<<i<<" ";
    }
}