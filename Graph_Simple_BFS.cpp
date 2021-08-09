#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,n,i,m;
	cin>>n>>m;
	queue<int>q;
	vector<int>g[10000];
    int vis[10000]={0};
	while(m--){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	q.push(1);
	while(!q.empty()){
	    int temp=q.front();
	    cout<<temp<<endl;
	    q.pop();
	    vis[temp]=1;
	    for(int i=0;i<g[temp].size();i++){
	        if(vis[g[temp][i]]==0)
	            q.push(g[temp][i]);
	        vis[g[temp][i]]=1;
	    }
	}
	
	return 0;
}