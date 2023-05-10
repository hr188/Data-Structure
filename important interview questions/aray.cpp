#include <iostream>
using namespace std;
int main(){
    string s = "this is my reverse";
    int n = s.length();
    int i =0;
    //logic to reverse a function word by word
    string res ="";
    while(i <n){
        while(i<n && s[i]==' ') i++;
        if(i>=n) break;
        int j = i+1;
        while(j<n && s[j]!=' ') j++;
        string ss = s.substr(i,j-i);
        int s =0;
        int e = ss.length()-1;
        while(s <e){
            swap(ss[s] , ss[e]);
            s++;
            e--;
        }
        if(res.length()==0) res = ss;
        else res = res + " " + ss;

        i = j+1;
    }
    cout<<res;
}