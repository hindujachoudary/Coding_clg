#include<bits/stdc++.h>
using namespace std;

int parent[100], rnk[100];
int find(int x){
	if(x!=parent[x])
		parent[x]=find(parent[x]);
	return parent[x];
}

void unon(int l, int m){
	int r=find(l);
	int s=find(m);
	if(r!=s){
		if(rnk[r] > rnk[s])
			parent[s]=r;
		else 
			parent[r]=s;

		if(rnk[r]==rnk[s])
			rnk[s]++;
	}
}


int main(){
	int n, m, w, i, cnt=0, ans=0, x, y;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>>edge;
	for(i=0; i<n; i++)
		parent[i]=i, rnk[i]=0;
	while(m--){
		cin>>x>>y>>w;
		edge.push_back({w,{x,y}});
	}
	sort(edge.begin(), edge.end());
	for(i=0; i<edge.size(); i++ ){
		int u=edge[i].second.first;
		int v=edge[i].second.second;
		if(cnt<n && find(u) != find(v)){
			ans+=edge[i].first;
			cnt++;
			unon(u,v);
		}
		if(cnt==n)
		    break;
	}
	cout<<ans<<endl;
	return 0;
}