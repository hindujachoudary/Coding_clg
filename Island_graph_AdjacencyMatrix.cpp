#include<bits/stdc++.h>
using namespace std;
struct cell{
	int x,y;
};
int main(){
	int m,n,i,j,island=0;
	queue<cell>q;
	cell temp,p;
	cin>>m>>n;
	int a[100][100],vis[100][100]={0};
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(vis[i][j]!=1 && a[i][j]==1){
				temp.x = i;
				temp.y = j;
				q.push(temp);
				vis[i][j]=1;
				while(!q.empty()){
					temp=q.front();
					q.pop();
					if(temp.y!=0 && a[temp.x][temp.y-1]==1 && vis[temp.x][temp.y-1]!=1){
							p.x=temp.x;
							p.y=temp.y-1;
							q.push(p);
							vis[p.x][p.y]=1;
					}
					if(temp.x!=0 && a[temp.x-1][temp.y]==1 && vis[temp.x-1][temp.y]!=1){
							p.x=temp.x-1;
							p.y=temp.y;
							q.push(p);
							vis[p.x][p.y]=1;
					}
					if(temp.y!=n-1 && a[temp.x][temp.y+1]==1 && vis[temp.x][temp.y+1]!=1){
							p.x=temp.x;
							p.y=temp.y+1;
							q.push(p);
							vis[p.x][p.y]=1;
					}
					if(temp.x!=m-1 && a[temp.x+1][temp.y]==1 && vis[temp.x+1][temp.y]!=1){
							p.x=temp.x+1;
							p.y=temp.y;
							q.push(p);
							vis[p.x][p.y]=1;
					}
				}
				island++;
			}
		}
	}
	cout<<island<<endl;

	return 0;
}