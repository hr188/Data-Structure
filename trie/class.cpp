#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    
    public:


    char ch;
    TrieNode* childern[26];
    bool isTerminal;

    
        TrieNode(char data){
            ch = data;
            for(int i = 0 ; i< 26 ;i++){
                childern[i]=NULL;
            }
            isTerminal = false;
        }
};

class trie{
    public:
        TrieNode* root;
        trie(){
           root = new TrieNode('\0') ;
        }

    void InsertUtils(string word ,TrieNode* root ){
        //base case 
        if(word.length()==0){
            root -> isTerminal= true;
            return;
        }
        // assuming all Caps letter
        int index = word[0]- 'A';
        TrieNode* child;

        if(root->childern[index]!=NULL){
            child = root->childern[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childern[index]= child;
        }
        InsertUtils(word.substr(1),child);

    }
    void insertWord(string inp){
        InsertUtils(inp , root);
    }

    bool searchutils(TrieNode* root , string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0] -'A';
        TrieNode* child;

        if(root->childern[index]!=NULL){
            child = root->childern[index];

        }
        else{
            return false;
        }
           return  searchutils(child,word.substr(1));   
        }
    bool searchWord( string word ){
        return searchutils(root,word);
    }


    void removeUtils(string word , TrieNode* root){
        if(word.length()==0){
            root -> isTerminal = false;
            return;
        }
        int index = word[0] -'A';
        TrieNode* child;
        child = root->childern[index];

        removeUtils(word.substr(1), child);
    }

    
    void remove(string word){
        if(searchWord(word)){
            removeUtils(word,root);
        }
    }
};

int main(){
    trie * t = new trie();
    t->insertWord("HELLO");
    t->insertWord("ARM");
    t->insertWord("TIME");

   cout<< t->searchWord("TIME")<<endl;
   t->remove("TIME");
   cout<< t->searchWord("TIME");
}