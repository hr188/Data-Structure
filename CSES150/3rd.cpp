#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s ; 
    cin>> s ;
    long long  maxi = 0; 
    long long count = 1;

    if(s.size()==1){
        cout<<count;
    }
    else{
    for(int i = 1 ; i < s.size() ; i++){
        if(s[i]==s[i-1]){
            count++;
        }
        else{
            count = 1;
            
        }
        maxi = max(maxi,count);
    }
    cout<<maxi;
    }
}