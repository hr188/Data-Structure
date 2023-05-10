#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> s;

    s.push(10);
    s.push(3);

    s.pop();

    cout<<"top element is "<< s.top()<<endl;
    s.pop();
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
}