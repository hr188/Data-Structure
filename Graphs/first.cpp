#include <iostream>
#include <list>
#include<unordered_map>
#include <utility>
#include <queue>

using namespace std;
template < typename T>

class graph{

    public:
    unordered_map<T, list<T> > adj;
    unordered_map<T, list<pair<T,T> > > adjj;
    
    void addEdge(T u , T v , bool direction ){
        //direction 0 undirected       1 directed 

        //first step create a edge from u to v
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
        
    }
    void addEdgeWeights(T u , T v , T weight,  bool direction  ){
        //direction 0 undirected       1 directed 

        //first step create a edge from u to v
        
        adjj[u].push_back({v,weight});

        if(direction==0){
            adjj[v].push_back({u,weight});
        }
        
    }
    void printList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    void printListWeight(){
        for(auto i : adjj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"(" <<j.first<<","<<j.second<<") ,";
            }
            cout<<endl;
        }
    }
    void bfs(T src){
      
      queue<T> q;
      unordered_map<T,bool> visited;

      q.push(src);
      visited[src] =true;

      while(!q.empty()){
        T front = q.front();
        q.pop();
        cout<<front<<" ";
          for(auto i : adj[front]){
            if(!visited[i]){
              q.push(i);
              visited[i]=true;
            }
          }
        
      }
    }
    void dfs(T src ,unordered_map<int,bool> &visited){
        cout<<src<<" ";
        visited[src]= true;
        for(auto neighbour : adj[src]){
          if(!visited[neighbour]){
            dfs(neighbour,visited);
          }
        }
    }
    
};



int main(){
//    int  nodes;
//    cout<< "Enter the number of nodes"<<endl;
//    cin>>nodes;
//    cout<<" enter the number of edges  "<<endl;
//    int edges;
//    cin>>edges;
//    cout<<"Enter connection ex a->b with space "<<endl;
//
//    graph <int> g;
//
//    for(int i = 0 ; i < edges ; i++){
//        int u , v;
//        cin>> u>> v;
//        g.addEdge(u,v,0);
//    }
//    g.printList();

    graph <int> gu;
    gu.addEdgeWeights(0,1,3,1);
    gu.addEdgeWeights(0,3,8,1);
    gu.addEdgeWeights(3,1,6,1);
    gu.addEdgeWeights(1,2,4,1);
    // gu.printListWeight();
    cout<<endl<<endl;
    int n = 4; //number of nodes for undirected graph logic
    gu.addEdge(0,1,1);
    gu.addEdge(0,3,1);
    gu.addEdge(3,1,1);
    gu.addEdge(1,2,1);
    gu.printList();
    cout<<endl;
    gu.bfs(0);
    cout<<endl;

    unordered_map<int,bool> visited;
    cout<<"printing DFS traversal"<<endl;
    for(int i =0 ; i<n ; i++){
      if(!visited[i]){
        gu.dfs(i,visited);
        
      }
    }

}