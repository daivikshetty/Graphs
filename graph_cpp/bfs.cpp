#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> bfs(int v,vector<int> adj[]){
      vector<int> brd;
      vector<int> vis(v+1,0);

      for(int i=1;i<=v;i++){
            if(!vis[i]){
                  queue<int> q;
                  q.push(i);
                  vis[i]=1;
                  while(!q.empty()){
                        int vert=q.front();
                        q.pop();
                        brd.push_back(vert);
                        for(int j=0;j<adj[vert].size();j++){            //for(auto it:adj[vert]){
                              if(!vis[adj[vert][j]]){                   //    if(vis[it]){
                                    q.push(adj[vert][j]);               //          }
                                    vis[adj[vert][j]]=1;                //                }
                              }
                        }
                  }
            }
      }
      return brd;
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

    vector<int> breadth=bfs(n,adj);

    cout<<"Depth First Traversal:\n";
    for(auto i:breadth)
      cout<<i<<" ";
    cout<<endl;


    return 0;
}
