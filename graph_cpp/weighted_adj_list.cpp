#include<iostream>
#include<vector>

using namespace std;

int main()
{
    cout<<"Enter no. of edges and vertices:\n";
    int n,m;
    cin>>m>>n;
    
    vector<pair<int,int>> adj[n+1];      //adjacency list for n vertices

    cout<<"Enter Edges\n";
    for(int i=0;i<m;i++){     //taking m edges as input
      int u,v,wt;             //wt is the weight
      cin>>u>>v>>wt;
      adj[u].push_back({v,wt});    //taking input for adj
      adj[v].push_back({u,wt});
    }

    for(int i=0;i<n+1;i++){
      cout<<i<<": ";
      for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j].first<<"->"<<adj[i][j].second<<" , ";
      }
      cout<<endl;
    }

    return 0;
}