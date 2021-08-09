#include<bits/stdc++.h>
using namespace std;

int vis[1000]={0};
int dfs(int node,int vis[1000],int dest){
	int i;
	vis[node]=1;
	if(node==dest)	
		return 1;
	int ans = 0;
	for(i=0;i<g[node].size();i++){
		if(vis[g[node][i]]==0)
			ans+=dfs(g[node][i],vis);
	}
	vis[node]=0;
	return ans;
}

int main(){
	int n,m,i,x,y,src,dest;
	cin>>n>>m;
	vector<int>g[1000];
	for(i=0;i<m;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>src>>dest;
	cout<<dfs(src,vis,dest)<<endl;
	return 0;
}