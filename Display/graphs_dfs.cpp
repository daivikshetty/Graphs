#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1,vector<int>(n+1,0));

    for(int i=0;i<m;i++){
          int x,y;
          cin>>x>>y;
          adj[x][y]=1;
          adj[y][x]=1;
    }

    for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
                cout<<adj[i][j]<<" ";
          }
          cout<<endl;
    }
      vector<vector<int>> adjL(n+1);
      for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            adjL[x].push_back(y);
            adjL[y].push_back(x);
      }

      vector<int>::iterator it;
      for(int i=1;i<=m;i++){
            cout<<i<<" -> ";
            for(it=adjL[i].begin();it!=adjL[i].end();it++){
                  cout<<*it<<" ";
            }
            cout<<endl;
      }
      
    return 0;
}