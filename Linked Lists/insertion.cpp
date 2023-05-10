#include <iostream>
#include <map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data ){
        this ->data = data;
        this ->next= NULL;
    }

    //destructor
    ~Node(){
        int value = this ->data;
        if(this->next !=NULL){
            delete next;
            next =NULL;
        }
        cout<<"memory is free for data "<< value <<endl;
    }
};
void insertionatTail(Node* &tail,int d ){
    Node* temp = new Node(d);
    tail ->next= temp;
    tail = temp;

}
void insertatHead(Node* &head , int d){
    //new node create 
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
    
}
void insertatPosition (Node* &tail ,Node* &head, int d , int pos){
    if(pos==1){
        insertatHead(head, d);
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
        insertionatTail(tail,d );
        return;
    }

    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp-> next;
    temp -> next = nodetoinsert;
}
void udado(int position , Node* &head ,Node* &tail){
    
    if(position ==1 ){  
        Node* temp = head ;
        head = head ->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt =1;
         

        while (cnt < position){
            prev = curr;
            curr = curr ->next;
            cnt++;
        }
        if(curr->next==NULL){
            prev ->next = curr->next;
            tail = prev;
            delete curr;
            prev=NULL;
            return;
        }
        prev ->next = curr -> next;
        curr ->next =NULL;
        delete curr;


    }
}


void print (Node*  &head ){
    Node *temp =head;
    while( temp != NULL){
        cout<<temp ->data<<" ";
        temp = temp ->next;

    }
    cout<<endl;
}
Node*  deleteduplicates(Node* head){
    if(head==NULL){
       return NULL;
   }
    map<int,bool>visited;
    Node* temp = head;
    Node* prev = NULL;

    while (temp!=NULL){
        
        if(visited[temp->data]==true&&(temp->next!=NULL)){
            prev ->next = temp ->next;
            Node* Nodetodelete = temp;
            delete Nodetodelete;
        }
        else{
            visited[temp->data]=true;
            prev = temp;
            temp = temp->next;      
         }
    }
    return head;
}
    Node* deleteDuplicates(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* curr = head;
        while (curr!= NULL){
            if((curr->next != NULL)&& (curr->data == curr-> next ->data)){
                Node* nexttonext = curr->next ->next;
                Node* deleteN= curr->next;
                delete(deleteN);
                curr->next = nexttonext;

            }
            else {
                curr = curr-> next;
            }
        }
        return head;
    }
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertionatTail(tail,50);
    print(head);
    insertionatTail(tail,25);
    print(head);
    insertatPosition(tail, head,30,3);
    print(head);
    insertatPosition(tail,head,30,3);
    print(head);
    insertatPosition(tail,head,30,3);
    print(head);
    insertatPosition(tail,head,50,5);
    print (head);
    cout<<endl;
    Node* ans = deleteduplicates(head);
    print(ans);
    
}