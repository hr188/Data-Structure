#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

template <typename T>
class graph{
    public:
      unordered_map<T, list<T> > adj;

    void addEdge(T u , T v , bool direction){
        adj[u].push_back(v);
        if(direction == 0 ){
          adj[v].push_back(u);
        }
    }
    void printList(){
      for(auto i : adj){
        cout<< i.first << "-> ";
        for(auto j : i.second){
          cout<< j <<" , ";
        }
        cout<<endl;
      }
    }
    void dfs( int src  , unordered_map<int, bool > &visited  ){
        cout << src <<" " ; 
        visited[src] = true;
        for(auto  i : adj[src] ){
          if(!visited[i] ){
            dfs(i,visited);
          }
        }

    }
    void topoSortDFS(int src  , unordered_map<int, bool > &visited , stack<int> &st){
        visited[src] = true;
        for(auto  i : adj[src] ){
          if(!visited[i] ){
            topoSortDFS(i,visited,st);
          }
        }
        st.push(src);
    }


};
int main() {
    graph<int> g ; 
    graph<int> gu ; 
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,0,1);
    g.addEdge(5,1,1);
    g.addEdge(5,4,1);
    
    g.printList();
    unordered_map<int, bool > visited;

    int v = 5;
    for(int i = 0 ; i<= v ; i++){
      if(!visited[i]){
        g.dfs(i ,  visited);
      }
    }
    cout<<endl<<" topological sort"<<endl;
    stack<int > st;
    unordered_map<int, bool > visited1;
    for(int i = 0 ; i<= v ; i++){
      if(!visited1[i]){
        g.topoSortDFS(i ,  visited1 ,st );
      }
    }
    while(!st.empty()){
      cout<< st.top() << " ";
      st.pop();
    }


}