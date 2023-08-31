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
    void DjkastraS(int src , int V){
        //TC : Olog(V+E)
        priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;
        pq.push({0,src}); //first pair {distance , NODE} 

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if (wt > dist[node]) {
            continue;
            }

            for(auto it : adj[node]){
                int Edgeweight = it.second;
                int currnode = it.first;
                if(wt  + Edgeweight  < dist[currnode]){
                    dist[currnode ]= wt + Edgeweight;
                    pq.push({dist[currnode ] ,currnode });
                }
            }
            for(int i =0 ; i< V ; i++){
                cout<< i <<"->"<<dist[i]<<endl;
            }
            
        }
    }
    //belman ford
    void BellmanFordAlgo(int n , int src ){
        //O(V*E)
        vector<int> dist (n, INT_MAX);
        dist[src] = 0;
        for(int i = 0 ; i< n-1 ; i++){
            for(auto it : adj){
                for(auto nbr : it.second){
                    int u = it.first;
                    int v = nbr.second;
                    int wt = nbr.second;
                    if(dist[u]!= INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        //TO CHECK IF NEGATIVE CYCLE IS PRESENT
        bool check = true;
        for(auto it : adj){
                for(auto nbr : it.second){
                    int u = it.first;
                    int v = nbr.second;
                    int wt = nbr.second;
                    if(dist[u]!= INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                        check = false;
                    }
                }
            }
        if(check == false )  cout<<"negative cycle is present";

        cout <<" printing distance array "<<endl;
        for(int i = 0 ; i<dist.size() ; i++){
            cout<< i << "-> "<<dist[i];
            cout<<endl;
        }

    }
    void FloydWarshal (int src , int n ){
        vector<vector<int>> dist( n , vector<int>(n,INT_MAX));

        for(int i = 0 ; i<n ; i++){
            dist[i][i] = 0;
        }
        for (auto i : adj){
            for(auto nbr : i.second){
                int u = i.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }
        for (int helper = 0 ; helper<n ; helper++){
            for(int src = 0 ; src < n ; src++){
                for(int dest = 0 ; dest < n ; dest++){
                    dist[src][dest] = min(dist[src][dest],dist[src][helper] + dist[helper][src]);
                }
            }
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
  cout<<endl;
  
}