class Solution {
  public:
    int countnodes(struct Node* root ){
        if(root==NULL){
            return 0;
        }
        int ans = countnodes(root->left) + countnodes(root->right) + 1;
        return ans;
    }
    bool CBT(struct Node* root , int count , int index ){
        if(root ==NULL){
            return true;
        }
        if(index >= count){
            return false;
        }
        else{
        bool left = CBT(root-> left  , count , 2*index + 1);
        bool right = CBT(root-> right ,count , 2*index +2);
        return left && right;
        }
    }
    bool isMAXBST(Node* root){
        if(root->right==NULL && root-> left == NULL){
            return true;
        }
        if(root-> right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMAXBST(root-> left);
            bool right = isMAXBST(root -> right );
            
            return ((left&&right)&& (root->data > root->left->data )&&(root->data > root->right->data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int count = countnodes(tree);
        int index = 0;
        
        if(CBT(tree , index , count ) && isMAXBST (tree)){
            return true;
        }
        else{
            return false;
        }
        
    }
};