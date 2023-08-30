class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    //using priority queue
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int> ,vector<pair<int,int> > , greater<pair<int,int>>> pq;
        vector<int>dist (V,INT_MAX);
        
        dist[S]= 0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
        
    }
};

//using set 
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
       set<pair<int,int>> st;
       vector<int> dist(V,10e9);
        dist[S] = 0;
       st.insert({0,S});
       
       while(!st.empty()){
           auto it = *(st.begin());
           int node = it.second;
           int dis = it.first;
           
           st.erase(it);
           for (auto i : adj[node]){
               int nbr = i[0];
               int edgeWt = i[1];
               if(dis + edgeWt < dist[nbr]){
                   if(dist[nbr] != 10e9)  st.erase({dist[nbr] , nbr});
                   
                   dist[nbr] = dis + edgeWt;
                   st.insert({dist[nbr] , nbr});
               }
           }
       }
       return dist;
    }
};