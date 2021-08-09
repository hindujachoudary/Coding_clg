#include<bits/stdc++.h>
using namespace std;

int vis[1000]={0};
vector<int>g[1000];
int dfs(int node,int vis[1000],int dest){
	int i;
	if(node==dest)
		return dest;
	vis[node]=1;
	int ans = node;
	for(i=0;i<g[node].size();i++){
		if(vis[g[node][i]]==0){
			ans=min(ans,dfs(g[node][i],vis,dest));
	        
		}
	}
	vis[node]=0;
	return ans;
}

int main(){
	int n,m,i,x,y,src,dest,j;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>src>>dest;
	cout<<dfs(src,vis,dest)<<endl;
	/*for(i=1;i<=n;i++){
	    cout<<i<<"->";
	    for(j=0;j<g[i].size();j++)
	        cout<<g[i][j]<<" ";
	   cout<<endl;
	}*/
	
	
	return 0;
}