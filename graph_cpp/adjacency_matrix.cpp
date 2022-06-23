#include<iostream>

using namespace std;

int main()
{
    cout<<"Enter no. of edges and vertices:\n";
    int n,m;
    cin>>n>>m;

    int adj[n+1][n+1];        //adjacency matrix for n vertices

    for(int i=0;i<n+1;i++){   //initialise all values of adj to 0
      for(int j=0;j<n+1;j++){
            adj[i][j]=0;
      }
    }

    cout<<"Enter Edges\n";
    for(int i=0;i<m;i++){     //taking m edges as input
      int u,v;
      cin>>u>>v;
      adj[u][v]=1;
      adj[v][u]=1;
    }

    for(int i=0;i<n+1;i++){
      for(int j=0;j<n+1;j++){
            cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }

    return 0;
}