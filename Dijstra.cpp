#include<bits/stdc++.h>
using namespace std;
int main(){
	//initialise all node distances to 99999
	int n, i, wt;
	int dist[10000];
	vector<int>g[10000];
	for(i = 0; i < n; i++){
		cin>>x>>y>>wt;
		g[x].push_back({y,wt});
		g[y].push_back({x,wt});
	}
	priority_queue<pair<int, int>>pq;
	for(i = 0; i < n; i++)
		dist[i]=99999;
	dist[src]=0;
	pq.push({0, src});
	while(!pq.empty()){
		wt=pq.front().first;
		x=pq.front().second;
		pq.pop();
		for(i = 0; i < g[x].size(); i++){
			if(dist[x]+ g[x][i].second < dist[g[x][i].first]){
				dist[g[x][i].first]=dist[x]+ g[x][i].second;
				pq.push({-dist[g[x][i].first], g[x][i].first});
			}
		}
	}

	return 0;
}
