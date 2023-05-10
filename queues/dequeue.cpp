#include <iostream>
#include <queue>
using namespace std;
int main(){
    deque<int>hr;
    hr.push_front(5);
    hr.push_back(10);
    cout<<"front is : "<<hr.front()<<endl;
    cout<<"end  is : "<<hr.back()<<endl;
}