#include<bits/stdc++.h>
using namespace std;

struct cell{
	int x,y;
};

int main(){
	int t,m,n,i,j,kl;
	int a[10001][10001];
	queue<cell>qu;
	cin>>t;
	while(t--){
		int vis[10001][10001]={0},island=0;
		cell p,temp;
		cin>>m>>n;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++)
				cin>>a[i][j];
		}
		int maxi=0,z=0;
		pair<int,pair<int,int> > dists[1000000];
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				dists[z++] = {a[i][j],{i,j}};
			}
		}
		sort(dists,dists+z);
		reverse(dists,dists+z);
		// for(i=0;i<z;i++)
		// 	cout<<dists[i].first<<" "<<dists[i].second.first<<" "<<dists[i].second.second<<endl;
		for(kl=0;kl<z;kl++){
			i=dists[kl].second.first;
			j=dists[kl].second.second;
			if(vis[i][j]==false){
				temp.x=i;
				temp.y=j;
				qu.push(temp);
				vis[i][j]=true;
				while(!qu.empty()){
					temp=qu.front();
					qu.pop();
					if(temp.x!=0 && a[temp.x][temp.y]>=a[temp.x-1][temp.y] && vis[temp.x-1][temp.y]==false){
						p.x=temp.x-1;
						p.y=temp.y;
						qu.push(p);
						vis[p.x][p.y]=true;
					}
					if(temp.x!=m-1 && a[temp.x][temp.y]>=a[temp.x+1][temp.y] && vis[temp.x+1][temp.y]==false){
						p.x=temp.x+1;
						p.y=temp.y;
						qu.push(p);
						vis[p.x][p.y]=true;
					}
					if(temp.y!=0 && a[temp.x][temp.y]>=a[temp.x][temp.y-1] && vis[temp.x][temp.y-1]==false){
						p.x=temp.x;
						p.y=temp.y-1;
						qu.push(p);
						vis[p.x][p.y]=true;
					}
					if(temp.y!=n-1 && a[temp.x][temp.y]>=a[temp.x][temp.y+1] && vis[temp.x][temp.y+1]==false){
						p.x=temp.x;
						p.y=temp.y+1;
						qu.push(p);
						vis[p.x][p.y]=true;
					}
				}
				island++;
			}
		}
		cout<<island<<endl;
	 }
	return 0;
}