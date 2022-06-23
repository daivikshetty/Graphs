#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cout<<"Enter no. of edges and vertices:\n";
    int n,m;
    cin>>m>>n;
    
    vector<int> adj[n+1];      //adjacency list for n vertices

    cout<<"Enter Edges\n";
    for(int i=0;i<m;i++){     //taking m edges as input
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);    //taking input for adj
      adj[v].push_back(u);    //not required for directed graph
    }

    for(int i=0;i<n+1;i++){
      cout<<i<<": ";
      for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }

    return 0;
}