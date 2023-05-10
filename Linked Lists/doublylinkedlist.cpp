#include <iostream>
using namespace std;
class Node {
  
    public:
    int data ;
    Node* next;
    Node* prev;

      //constructor 
    Node(int d){
        this ->data = d;
        this ->prev = NULL;
        this ->next = NULL;
    }  
    //destructor
    ~Node(){
        int val = this -> data;
        if(next !=NULL){
            delete next;
            next =NULL;
        }
        cout<<"memory free for "<< val <<endl;
    }
};
void print(Node* head ){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
int getlength (Node* head){
    Node* temp = head;
    int len=0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}
void InsertAtHead(Node* &head , Node* &tail, int d){
    if (head==NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
    Node* temp = new Node(d);
    temp ->next = head;
    head  ->prev = temp;
    head= temp;
    }
}
void InsertAtTail(Node* &head, Node* &tail , int d){
     if (tail==NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else {
    Node* temp = new Node(d);
    tail ->next = temp;
    temp ->prev = tail;
    tail = temp;
    }
}
void insertatPosition (Node* &tail ,Node* &head, int d , int pos){
    if(pos==1){
        InsertAtHead(head,tail,  d);
        return;
    }
    Node* temp = head;
    int cnt =1;
    while (cnt < pos -1){
        temp = temp -> next;
        cnt++; 
    }
    //at last hai agar to
    if(temp->next == NULL){
        InsertAtTail(head,tail,d );
        return;
    }

    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp-> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}
void deleteNode(Node* &head, int pos){
    if(pos==1){
        Node *temp = head;
        temp ->next ->prev = NULL;
        head = temp->next;
        temp ->next =NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt =1;
        while(cnt < pos){
            prev = curr;
            curr= curr ->next;
            cnt++;
        }
        prev -> next = curr-> next ;
        curr-> next = NULL;
        curr-> prev = NULL;
        delete curr;
    }
}
int main( ){
    
    Node* head = NULL;
    Node* tail = NULL;
    
    // cout << getlength(head)<<endl;
    InsertAtHead(head,tail, 20);
    print (head );


    InsertAtHead(head,tail,15);
    print (head );


    InsertAtHead(head,tail,10);
    print (head );

    InsertAtTail(head, tail,30);
    print (head );
    
    insertatPosition(tail,head ,100, 5);
    print (head);
    
    deleteNode(head,5);
    print (head);
    cout<< "head is :" << head ->data<<endl;
    cout<< "tail is : "<< tail ->data;
}