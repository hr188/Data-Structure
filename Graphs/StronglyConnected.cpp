#include <iostream>       // std::cout
#include <queue>          // std::queue
using namespace std;
#include <unordered_map>
#include <queue>
#include <list>
#include <stack>

class graph{
    public:
        unordered_map<int,list<int> >adj;

    void addEdge(int u , int v , bool direction ){
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
  
    void dfs1(int src , unordered_map<int,bool >& visited , stack<int> &s){
        visited [src] = true;
        for(auto i : adj[src]){
        if(!visited[i]){
            dfs1(i,visited,s);
        }
        }
        s.push(src);
    }
    void dfs2(int src ,unordered_map<int,bool >& visited , unordered_map<int,list<int > >adjList){
        visited[src]= true;
        
        for(auto i : adjList[src]){
            if(!visited[i]){
                dfs2(i,visited,adjList);
            }
        }
    }
    int  StronglyConnectedComponents(int n ){
        stack<int> s;
        unordered_map<int, bool > visited;
        //step 1 find topo ordering  
        for(int i= 0 ; i<n ; i++ ){
           if(!visited[i]) dfs1(i, visited,s);
        }
        //step 2 reversal of edges
        unordered_map<int,list<int > >adjList;
        for(auto i : adj){
            for(auto j : i.second){
                int u = i.first;
                int v = j;
                adjList[v].push_back(u);
            }
        }

        //step 3 finding number of components using dfs
        int count = 0 ;
        unordered_map<int,bool> visited2;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(!visited2[top]){
                dfs2(top,visited2 ,adjList );
                count++;
            }
        }
        return count;
    }
     void FindBridges(int src , int parent , int &timer , vector<int> &tin , vector<int> &low ,  unordered_map<int,bool> vis   ){
        vis[src]= true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr : adj[src]){
            if(nbr== parent) continue;

            if(!vis[nbr]){
                //call
                FindBridges(nbr, src , timer , tin, low ,vis);
                //call se wapis aate hue first update low and check if bridge is present
                low[src] = min(low[nbr], low[src]);
                if(low[nbr] > low[src]) {
                    //means that a bridge is present
                    cout<< nbr <<"-->" <<src<<"is a bridge" <<endl;
                }
            }
            else{
                low[src] = min(low[nbr], low[src]);
            }
        }
        
    }
};
int main(){
    graph gu;
    gu.addEdge(0,1,1);
    gu.addEdge(1,2,1);
    gu.addEdge(2,3,1);
    gu.addEdge(3,0,1);
    gu.addEdge(2,4,1);
    gu.addEdge(4,5,1);
    gu.addEdge(5,6,1);
    gu.addEdge(6,4,1);
    gu.addEdge(6,7,1);
    gu.printList();
    cout<<endl;
    int SCC  = gu.StronglyConnectedComponents(8);
    cout<< SCC <<endl;
    int n = 8 ;   
    int src =0 ;
    int parent = -1;
    int timer = 1;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int,bool>vis;
    gu.FindBridges(src, parent ,timer , tin ,low , vis );

}
