#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stackSort(int node,vector<int> adj[],vector<int> vis,stack<int> st){
    vis[node]=1;

    for(auto it:adj[node]){
        if(!vis[it])
            stackSort(it,adj,vis,st);
    }

    st.push(node);
}

vector<int> topSort(int n,vector<int> adj[]){
    stack<int> st;
    vector<int> vis(n,0);

    for(int i=1;i<=n;i++){
        if(!vis[i])
            stackSort(i,adj,vis,st);
    }

    vector<int> sort;
    while(!st.empty()){
        sort.push_back(st.top());
        st.pop();
    }
    return sort;
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
    }

    cout<<"Adjacency List:\n";
    for(int i=0;i<n+1;i++){
      cout<<i<<": ";
      for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }

    vector<int> srt=topSort(n,adj);

    cout<<"Topological Sorted Graph:\n";
    for(auto i:srt)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}