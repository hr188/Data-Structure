#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

void dfstopo( vector< vector<int> > &adj , int src , unordered_map<int , bool >& visited , stack<int> &st){
        visited[src] = true;
        
        for(auto i : adj[src]){
            if(!visited[src]){
            dfstopo(adj , src, visited , st);
            }
        }
        st.push(src);
    }
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector< vector<int> > adj;
    for(int i = 0 ; i < e ; i++){
        int u = edges[i][0];
        int v = edges[0][i];
        adj[u].push_back(v);
    }

    

    unordered_map<int , bool > visited;
    stack<int> st;

    for (int i = 0 ; i<v  ; i++){
        if(!visited[i]){
            dfstopo( adj , i , visited , st);
        }
    }

    vector<int> ans ;
    while(!st.empty()){
        int s = st.top();
        ans.push_back(s);
        st.pop();
    }
}
int main(){

}