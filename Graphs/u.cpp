#include <iostream>
#include <queue>
using namespace std;
int main(){
int v,e,a,b;
    cout<<"Enter number of vertex and edges: ";
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=1;i<=e;i++)
    {
        cout<<"Edge "<<i<<" : ";
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"Source\t:\tDestination"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<"\t:\t";
        for(auto j:adj[i])
            cout<<j<<",";
        cout<<endl;
    }
    vector<int> visited(v);
    queue<int> q;
    cout<<"BFS Sequence: ";
    q.push(0);
    visited[0]=1;
    while(q.size()!=0)
    {
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto i:adj[x])
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }
    }

}    