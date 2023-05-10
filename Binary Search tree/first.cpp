#include <iostream>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
Node* InsertIntoBst(Node* root , int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
       root -> right = InsertIntoBst(root->right , d);
    }
    else{
      root -> left = InsertIntoBst(root->left , d);
    }
    return root;
}
void TakeInput(Node* &root){

    int data ;
    cin>> data;
    while(data!=-1){
        InsertIntoBst(root , data);
        cin>> data;
    }
}
void LevelOrderTraversal(Node * root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp== NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp -> data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter the data Of The BST"<<endl;
    TakeInput(root);
    LevelOrderTraversal(root);
}