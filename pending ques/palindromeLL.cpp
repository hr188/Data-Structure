 bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }
        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            if(s==e){
                s++; 
                e--;
            }
            else{
                return false;
            }
            
        }
        return true;
    }