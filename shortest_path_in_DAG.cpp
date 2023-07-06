//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  stack<int> st;
  void dfs(int node,int vis[],vector<pair<int,int>> adj[]){
      vis[node]=1;
      for(auto it:adj[node]){
          if(!vis[it.first]){
              dfs(it.first,vis,adj);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int vis[N]={0};
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
            }
        }
        vector<int> dis(N);
        for(int i=0;i<N;i++){
            dis[i]=1e9;
        }
        dis[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
               int u=it.first;
               int w=it.second;
               if(dis[node]+w<dis[u]){
                   dis[u]=w+dis[node];
               }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends