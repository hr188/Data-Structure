#include <iostream>
using namespace std;
class Kqueue{
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freespot;
    int *next;


    Kqueue(int n , int k){
        this  -> n = n;
        this -> k = k;
        front = new int [k];
        rear = new int [k];
        for (int  i = 0; i < k; i++)
        {
            front[i]=-1;
            rear [i]=-1;
        }
        next  = new int[n];
        for (int  i = 0; i < n; i++)
        {
            next[i]= i+1;

        }
        next[n-1]= -1;
        arr = new int [n];

        freespot = 0;
        

    }

    void enqueue(int data , int qn){
        if(freespot == -1){
            cout<<"queue is full "<<endl;
            return ;
        }
        
        //find first free index 
        int  index = freespot;

        //free spot update 
        freespot = next[index];

        // check whether first index
        if(front[qn -1] == -1){
            front[qn-1] = index ;
        }
        else{
            next[rear[qn-1]] = index;

        }
        //update next
        next[index] = -1;

        rear[qn -1] = index;

        arr[index] = data ;
    }

};
int main(){
    
}