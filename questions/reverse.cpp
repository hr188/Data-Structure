#include <iostream>
#include <vector>
using namespace std;
vector<int> reverse (vector <int> v){
int s=0, e=v.size()-1;
while(s<=e){
    swap(v[s],v[e]);
    s++;
    e--;
}
return v;

}
int main(){

vector<int>v;
v.push_back(10);
v.push_back(11);
v.push_back(12);
v.push_back(13);
v.push_back(14);
v.push_back(15);
vector<int> ans =reverse(v);
int n = ans.size();
for(int i : ans){

cout<< i <<endl;

}

}