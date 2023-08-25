#include <iostream>       // std::cout
#include <queue>          // std::queue
using namespace std;
#include <unordered_map>
#include <queue>
#include <list>
template <typename T>
class graph{
    public:
        unordered_map<T,list<T> >adj;

    void addEdge(T u , T v , bool direction ){
        //0 undirected //1 directed 
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    void printList( ){
        for(auto i : adj){
            cout<< i.first<<"->"; 
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
    void bfs(int src , unordered_map<int,int >& visited){
        queue <int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int front  = q.front();
            q.pop();
            cout<<front << " ";
            for(auto i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void dfs(int src , unordered_map<int,int >& visited){
        cout<<src<<" ";
        visited [src] = true;
        for(auto i : adj[src]){
        if(!visited[i]){
            dfs(i,visited);
        }
        }
    }
};
int main(){
    graph<int> gu;
    gu.addEdge(0,1,0);
    gu.addEdge(1,2,0);
    gu.addEdge(2,3,0);
    gu.addEdge(3,0,0);
    gu.printList();
    cout<<endl;

    unordered_map<int,int > visited;
    int n = 3; 
    for(int i = 0 ; i <=3 ; i++){
        if(!visited[i])
        gu.dfs(i , visited);
    }

}
