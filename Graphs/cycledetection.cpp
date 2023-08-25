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

    
    void addEdge(T u , T v , bool direction ){
        //direction 0 undirected       1 directed 

        //first step create a edge from u to v
        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
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
    
    void bfs(int src , unordered_map<int,bool>& visited){
      
      queue<int> q;

      q.push(src);
      visited[src] =true;

      while(!q.empty()){
        int front = q.front();
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
    bool cycleDetectionBfs(int src , unordered_map<int,bool>& visited){
      
      queue<int> q;
      unordered_map<int, int> parentMap;

      q.push(src);
      visited[src] =true;
      parentMap[src]= -1;

      while(!q.empty()){
        int front = q.front();
        q.pop();
          for(auto i : adj[front]){
            if(!visited[i]){
              q.push(i);
              visited[i]=true;
              parentMap[i] = front;
            }
            else{//already visited
              if(i != parentMap[front]){ //parent different 
                  return true;
              }
            }
          }
      }
      return false;
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

    bool cycleDetectionDfs(int src , unordered_map<int,bool> &visited ,int parent ){
      visited[src] = true;
      for(auto i : adj[src]){
        if(!visited[i]  ){
          bool checkAage = cycleDetectionDfs(i , visited,src);
          if(checkAage == true){
            return true;
          }
        }
        else{
          if(i != parent){
            return true;
          }
        }
      }
      return false;
    }
    bool cycleDetectionDirectedDfs(int src , unordered_map<int,bool> &visited,  unordered_map<int,bool> &RecursionRecord){
      visited[src] = true;
      RecursionRecord[src] = true;

      for(auto i : adj[src]){
        if(!visited[i]){
          bool aageKiCall = cycleDetectionDirectedDfs(i, visited , RecursionRecord );
          if(aageKiCall == true){
            return true;
          }
        }
        if( visited[i] && RecursionRecord[i] == true){
            return true;
        }
        
      }
      RecursionRecord[src]= false; 
      return false;
    }
    
};



int main(){


   graph<int>gu;
    int n = 4; //number of nodes for undirected graph logic
    gu.addEdge(0,1,0);
    gu.addEdge(1,2,0);
    gu.addEdge(2,3,0);
    gu.addEdge(3,4,0);
    gu.addEdge(4,2,0);
    gu.printList();
    
    cout<<endl;

    unordered_map<int,bool> visited;
    // bool ans = false;
    // for(int i =0 ; i<=4 ; i++){
    //   if(!visited[i]){
    //     ans  = gu.cycleDetectionBfs(i,visited);
    //     if(ans){
    //       cout<<"cycle detected "<<endl;
    //       break;
    //     }
    //   }
      
    // }
    // if(!ans){
    //     cout<<" NO Cycle detected"<<endl;
    // }

    bool ans = false;
    for(int i =0 ; i<=4 ; i++){
      if(!visited[i]){
        ans  = gu.cycleDetectionDfs(i,visited ,-1);
        if(ans){
          cout<<"cycle detected "<<endl;
          break;
        }
      }
      
    }
    if(!ans){
        cout<<" NO Cycle detected"<<endl;
    }
    cout<<endl;
    cout<< "cycle detection using dfs in a undirected graph" <<endl;

    graph<int> g ;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    // g.addEdge(4,0,1);
    g.printList();

    unordered_map<int,bool> visitedA;
    unordered_map<int,bool> record;
    bool anss = false;
    for(int i =0 ; i<=4 ; i++){
      if(!visitedA[i]){
        anss  = g.cycleDetectionDirectedDfs(i,visitedA ,record);
        if(anss){
          cout<<"cycle detected "<<endl;
          break;
        }
      }
      
    }
    if(!anss){
        cout<<" NO Cycle detected"<<endl;
    }

}