#include <iostream>
using namespace std;
void reverse ( string ch){
    int s =0, e=ch.length()-1;
    while ( s<e ){
     swap(ch[s],ch[e]);
      s++;
      e--;
    }
    
}

int main(){
    string s,ch;
    cout<<"Enter string"<<endl;
    cin>>s;
    
    for (int  i = 0; i < s.length() ;i ++)
    {   
        ch.push_back(s[i]);
        if (ch[i]==' '|| ch[i]==0)
        {
          reverse(ch);
        }
        
    }
    for(int i=0; i < ch.length(); i++){
      cout<<ch[i];
    }

}