//code  studio 
#include <iostream>
#include <vector>
using namespace std;
void solve (string str , string output , vector<string>& ans,int index ){
    //base case 
    if(index>=str.length()){
        if(output.length()>0){
        ans.push_back(output);
        }
        return;
    }

    //exclude 
    solve (str, output , ans, index+1);
    //include 
    char element = str[index];
    output.push_back(element);
    solve (str, output , ans, index+1);

}
int main(){



}