#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,u,v,temp,island=0, j,i;
    cin>>n>>m;
    vector<int> g[100001];
    queue<int>q;
    int vis[100001]={0};
    while(m--){
      cin>>u>>v; 
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for(i=1;i<=n;i++){
        if(vis[i]!=1){
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                temp=q.front();
                q.pop();
                for(j=0;j<g[temp].size();j++){
                    if(vis[g[temp][j]]!=1){
                        q.push(g[temp][j]);
                        vis[g[temp][j]]=1;
                     }    
                } 
            }
            island++;
        }
    }
    if(island>1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}