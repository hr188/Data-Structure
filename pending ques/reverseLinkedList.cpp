void reverse(LinkedListNode<int>* &head,LinkedListNode<int>* curr , LinkedListNode<int>* prev ) {
    //base case 
    if(curr==NULL){
        head=prev;
        return;
    }
    LinkedListNode<int>* forward = curr-> next;
    reverse(head, forward , curr);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head , curr , prev);
    return head;

    //itreative approach 
    
//     if(head==NULL || head ->next == NULL){
//         return head;
//     }
//     LinkedListNode<int>* prev = NULL;
//     LinkedListNode<int>* curr = head;
//     LinkedListNode<int>* forward =NULL;
    
//     while(curr!=NULL){
//         forward = curr ->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
}

//recursive approach
ListNode* reverse(ListNode* head){
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode* chota = reverse(head->next);
        head ->next ->next = head;
        head ->next = NULL;
        return chota;
}