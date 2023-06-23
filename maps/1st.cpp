#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main(){
    unordered_map<int,int> m;

    //insertion method 1
    pair<int,int> p= make_pair(6,2);
    m.insert(p);

    //method 2
    pair<int,int> pair2(2,4);
    m.insert(pair2);

    //method 3 
    m[5] = 23;

    cout<<m.at(5)<<endl;

    //to check if key is present
    cout<<m.count(5)<<endl; //retrurns 1 if present 0 if not


    cout<<m.size()<<endl<<endl;

    //traversing 
    for(auto i:m){
        cout<<i.first<< "  "<<i.second<<endl;
    }


    cout<<"use of iterator"<<endl<<endl;

    //iterator
    unordered_map<int,int> :: iterator it =m.begin();
    while(it!=m.end()){
        cout<<it->first<< "  "<<it->second<<endl;
        it++;
    }

}