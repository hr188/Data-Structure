#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;

class graph{
    unordered_map<int,list<int> > adj;
    public:
        void AddEdge(int u , int v , bool direction){
            adj[u].push_back(v);

            if(direction){
                adj[v].push_back(u);
            }
        }

        void PrintList(){
            for(auto i : adj){
                cout<<i.first<<"-->";
                for(auto nbr :i.second){
                    cout<<nbr<<", ";
                }
                cout<<endl;
            }
        }
        void dfs(int source , unordered_map<int,bool> &visited){
            visited[source] = true;
            cout<< source<<" " ;


            for(auto nbr : adj[source]){
                if(!visited[nbr]){
                    dfs(nbr,visited);
                }
            }
        }
        void bfs(int src , unordered_map<int, bool>&visited){
            queue<int> q;
            visited[src] = true;
            q.push(src);

            while(!q.empty()){
                int front  = q.front();
                q.pop();
                cout<<front<<" ";

                for(auto nbr : adj[front] ){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }
};
int main(){
    graph gu;
    gu.AddEdge(0,1,0);
    gu.AddEdge(0,2,0);
    gu.AddEdge(1,2,0);
    gu.AddEdge(2,3,0);
    gu.AddEdge(3,1,0);
    gu.AddEdge(4,1,0);
    gu.AddEdge(3,2,0);

    gu.PrintList();

    unordered_map<int,bool> visited;
    int vertex = 4;
    for(int i = 0 ; i <=vertex ; i++){
        if(!visited[i]){
            gu.bfs(i, visited);
        }
    }

}