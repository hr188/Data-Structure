#include <iostream>
#include <map>
using namespace std;
class Node {
    public:
    int data;
    Node* next;

    //constructor;
    Node(int d){
        this ->data = d;
        this ->next = NULL;
    }
    //destructor;
    ~Node(){
        int value = this ->data;
        if(this-> next != NULL){
            delete next ;
            next = NULL;
        }
        cout<<"memory free for "<<value <<endl;
    }

};
void print (Node* tail ){
    Node* temp = tail;
    do{
        cout<<tail -> data<<" ";
        tail = tail -> next;
    }while(tail != temp);
    cout<<endl;
}
void InsertNode(Node* &tail , int element, int d ){
    if(tail==NULL){
        Node* newnode = new Node(d);
        tail = newnode;
        newnode ->next = newnode;
    }
    else{
        //non empty list 
        Node* curr = tail;
        while (curr->data != element){
            curr= curr->next;
        }
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr ->next = temp;
    }
}

void delteNode(Node* &tail, int value){
    if(tail==NULL){
        cout<<"not possible "<<endl;
        return;
    }
    else {
        Node* prev = tail;
        Node* curr = prev ->next;
        while (curr->data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev ->next = curr ->next;
        if(tail==curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
bool detectloop(Node* head){
    if(head==NULL){
        return true;
    }
    map <Node* , bool> visited;
    Node* temp = head;
    while (temp!=NULL){
        if(visited[temp]==true){
            return 1;
        }
        visited[temp]=true;
        temp = temp->next;
    }
    return 0;
}
Node* FloydDetectLoop(Node* head){
    if (head== NULL)
    {
        return NULL;
    }
    
    Node* slow =head;
    Node* fast =head;
    
    while (slow !=NULL && fast != NULL){
        fast = fast->next;
        if(fast !=NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if(fast == slow ){
            cout <<"present at "<<slow ->data <<endl;
            return slow;
            
        }
    }
return NULL;

}
Node* GETNODE(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection = FloydDetectLoop(head);
    Node * slow=head;
    while(slow!=intersection){
        slow = slow-> next;
        intersection=intersection -> next;
    }
    return slow;
}
void* removeloop(Node* head){
    if(head==NULL){
        return ;
    }

    Node* startloop =   GETNODE( head);
    Node* temp = startloop;
    while(temp->next != NULL){
        temp= temp -> next;
    }
    temp -> next = NULL;
   
}
int main(){
    Node* tail =NULL;
    //empty list 
    InsertNode(tail,5,3);
    print (tail);
    InsertNode(tail,3,5);
    print (tail);
    InsertNode(tail,5,7);
    print (tail);
    InsertNode(tail,7,9);
    print (tail);
    InsertNode(tail,3,27);
    print (tail);
    
    if(FloydDetectLoop(tail) != NULL){
        cout<<"loop is present"<<endl;
    }
    else
    cout<<"not";
    Node* ans = GETNODE(tail);
    cout<<"loop is present at "<<ans->data;

}