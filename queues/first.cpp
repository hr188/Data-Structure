#include <iostream>
#include <queue>
using namespace std;
int main(){
queue<int> q;
    q.push(3);
    q.push(5);
    q.push(12);
    q.pop();
    cout<<"front is :"<<q.front()<<endl;
    cout<<"size of queue is : "<<q.size()<<endl;
    

}