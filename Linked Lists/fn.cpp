void InsertAtTail(Node* &head , int d){
    //joogadbaazi 
    Node* temp =head;
    Node* hr = new Node(d);
    int cnt = 0;
    while(cnt< getlength(head)-1){
        temp = temp ->next;
        cnt++;
    }
    temp ->next = hr;
    hr->prev = temp;


}