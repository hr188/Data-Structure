#include <iostream>
#include<stack>
#include <vector>
using namespace std ;
// baisc questions of stack

void sortedInsert(stack<int> &stack, int num) {

    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}
//ending of sort stack

//revrse a stack
void insertAtBottom(stack<int>& Stack, int x){
    if(Stack.empty()){
        Stack.push(x);
        return ;
    }
    int num = Stack.top();
    Stack.pop();

    insertAtBottom(Stack , x);
    Stack.push(num);

}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack,num);

}
//ending of revrse


//insert at bottom
void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    int num = myStack.top();
    myStack.pop();

    solve(myStack , x);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack ,x);
    return myStack;
}
//ending



//insert at middle of the stack
void solve(stack<int>& myStack, int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    int num = myStack.top();
    myStack.pop();

    solve(myStack , x);
    myStack.push(num);

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack ,x);
    return myStack;
}
//ending  