#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, m, i, j, weight, u;
	cin>>n>>m;
	priority_queue<pair<int,int>>pq;
	int dist[n];
	while(m--){
		cin>>x>>y>>w;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	dist[0]=0;
	for(i=1; i<n; i++)
		dist[i]=INT_MAX;
	pq.push({0,0});
	while(!pq.empty()){
		weight=pq.top().first;
		u=pq.top().second;
		pq.pop();
		vis[u]=1;
		for(i=0; i<g[u].size(); i++){
			if(vis[g[u][i].first]==0 && g[u][i].second < dist[g[u][i]]){
				pq.push({g[u][i].second, g[u][i]});
				dist[g[u][i]]=g[u][i].second;
			}
		}
	}	



}