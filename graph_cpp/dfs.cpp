#include<iostream>
#include<vector>
using namespace std;

void dfsGraph(int i,vector<int> &vis,vector<int> adj[],vector<int> &ans){
      ans.push_back(i);
      vis[i]=1;
      for(auto it:adj[i]){
            if(!vis[it])
                  dfsGraph(it,vis,adj,ans);
      }
}

vector<int> dfs(int v,vector<int> adj[]){
      vector<int> vis(v+1,0);
      vector<int> dpt;
      for(int i=1;i<=v;i++){
            if(!vis[i])
                  dfsGraph(i,vis,adj,dpt);
      }
      return dpt;
}

int main()
{
     cout<<"Enter no. of edges and vertices:\n";
    int n,m;
    cin>>m>>n;
    
    vector<int> adj[n+1];

    cout<<"Enter Edges\n";
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

      cout<<"Adjacency List:\n";
    for(int i=0;i<n+1;i++){
      cout<<i<<": ";
      for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }

    vector<int> depth=dfs(n,adj);

    cout<<"Depth First Traversal:\n";
    for(auto i:depth)
      cout<<i<<" ";
    cout<<endl;
    return 0;
}