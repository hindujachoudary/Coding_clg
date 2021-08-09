#include<bits/stdc++.h>
using namespace std;

vector<int>g[10000];
int vis[10000];
void dfs(int node,int vis[10000]){
	vis[node]=1;
	cout<<node<<endl;
	for(int i=0;i<g[node].size();i++)
		if(vis[g[node][i]]==0)
			dfs(g[node][i],vis);
}

int main(){
	int x,y,n,i,m;
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		g[x].push_back(y); // pushing all edges.
		g[y].push_back(x); // reverse edge also. (symmetric)
	}
	dfs(1,vis); // doing dfs from Node 1.
	return 0;
}