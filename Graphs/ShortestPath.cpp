#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <limits.h>
using namespace std;

class graph {
    public:
    unordered_map<int , list<pair<int,int>> > adj;

    void addEdge(int u , int v , int w , bool direction ){
      adj[u].push_back({v,w});
      if(direction ==0) {
          adj[v].push_back({u,w});
      }
    }
    
    void printList (){
      for(auto i : adj){
        cout<< i.first<< "->";
        for(auto j : i.second){
          cout<< "("<< j.first << " " <<j.second <<")"<<" ";
        }
        cout<<endl;
      }
    }
    void shortestPathbfs(int src , int dest ){
      queue<int> q;
      unordered_map<int , bool > visited;
      unordered_map<int,int> parent;

      q.push(src);
      visited[src] = true;
      parent[src]= -1;
      while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto i : adj[front]){
          if(!visited[i.first]){
            q.push(i.first);
            visited[i.first] = true;
            parent[i.first] = front;
          }
        }
      }
    
        vector<int> ans;
        int node = dest;
        while(node != -1){
          ans.push_back(node);
          node = parent[node];
        }
      
      reverse(ans.begin() , ans.end());
      cout<<"printing ans " << endl;
      for(auto i: ans){
          cout<<i<<" " ;
      }
      cout<<endl;

    }

    void topoSortDFS(int src  , unordered_map<int, bool > &visited , stack<int> &st){
        visited[src] = true;
        for(auto  i : adj[src] ){
          if(!visited[i.first] ){
            topoSortDFS(i.first,visited,st);
          }
        }
        st.push(src);
    }
    void shortestPathDfs(int dest , stack<int> &st , int n  ){
        vector<int> dist(n , INT_MAX -10000);
        int src = st.top();
        st.pop();
        dist[src]= 0;
        for(auto nbr : adj[0]){
                if(dist[0] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[0] + nbr.second;
                }
            }
        while(!st.empty()){
            int topElement = st.top();
            st.pop();
            if(dist[topElement]!= INT_MAX){
            for(auto nbr : adj[topElement]){
                if(dist[topElement] + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = dist[topElement] + nbr.second;
                }
            }
            }
            
        }
        for(int i =0 ; i< n ; i++){
                cout<< i <<"->" <<dist[i]<<endl;
            }

    }
};
int main() {
  graph g;
  g.addEdge(0,1,5,0);
  g.addEdge(0,2,3,0);
  g.addEdge(2,1,2,0);
  g.addEdge(1,3,3,0);
  g.addEdge(2,3,5,0);
  g.addEdge(2,4,6,0);
  g.addEdge(4,3,1,0);


  g.printList();
  int src= 0;
  int dest = 4;

  g.shortestPathbfs(src, dest );

  //topo sort ka mamla
  stack<int> topoOrder;
  unordered_map <int,bool> vis;
  int srcc= 0;

  g.topoSortDFS(srcc , vis ,topoOrder ); 
  int destt = 3;
  g.shortestPathDfs(3 , topoOrder , 5);
  
}