#include <iostream>
#include <queue>

using namespace std;
class node{
    public:
        int data ;
        node* left;
        node* right;
        
        //constructor 
        node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right  = NULL ;

        }
};
node* getTree (node* root){
    cout << " Enter data : "<< endl;
    int data ;
    cin >> data;
    root = new node (data);

    //recursive way mai input lele
    if(data == -1 ){
        return NULL;
    }

    //left part ke liye input lele;
    cout <<" Enter the left element of  " << data << endl;
    root  -> left  = getTree( root -> left );
    cout << " Enter the right element of "<< data <<endl;
    root  -> right   = getTree( root -> right  );

    return root; 
}
//level order traversal 
void LevelOrderTraversal(node * root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
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
void inorder(node* root){
    if(root== NULL){
        return ;
    }
    inorder(root -> left);
    cout<< root -> data << " ";
    inorder(root -> right);
}
void preorder(node* root){
    //nlr
    if(root == NULL){
        return ;
    }
    cout <<root -> data <<" ";
    
    preorder(root -> left);
    preorder(root->right);
}
void postorder(node * root ){
    //lrn
    if(root == NULL){
        return ;
    }
    postorder(root -> left);
    postorder(root -> right );
    cout << root -> data << " ";
}
node* buildfromlevelorder(node* root){
    queue<node*> q;
    
    cout << " enter data for root "<<endl;
        int data ;
        cin>> data ;
        root = new node (data );
        q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"enter the left elemnt for : "<< temp -> data<<endl;
        int leftdata;
        cin>> leftdata;
        if(leftdata != -1){
            temp -> left = new node (leftdata);
            q.push(temp -> left);
        } 

        cout << " enter the elements for right "<< temp -> data<< endl;
        int rightdata;
        cin >> rightdata;
        if(rightdata!= -1){
            temp  -> right = new node( rightdata);
            q.push(temp -> right );
        }
    }
}
int main(){
    node * root = NULL;
    root = getTree(root);
    LevelOrderTraversal(root);
    cout<<endl << "in order reversal "<<endl;
    inorder(root);
    cout << endl << " pre order traversal "<< endl;

    preorder(root);
    cout << endl <<  " post order traversal "<< endl;

    postorder(root);

}