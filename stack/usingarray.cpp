#include <iostream>
using namespace std;
class stack {
    public:
    int * arr;
    int top ;
    int size;

    stack(int size ){
        this ->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else
        {
            cout<<"stack underflow"<<endl;
        }

    }
    int peek(){
        if(top>=0 && top < size){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top== -1){
            return true;
        }
        else 
        return false;
    }
};
int main(){
    stack st(5);
    st.push(45);
    st.push(44);
    st.push(111);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty()){
        cout<<"khali hai bha"<<endl;
    }
    else
    cout<<"not";

}