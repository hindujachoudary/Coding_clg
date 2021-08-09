#include<bits/stdc++.h>
using namespace std;





int main(){
	int n, m, i, j, vis[1000][1000], cnt=0, maxi=0, x, y, a[100][100];
	cin>>n>>m;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin>>a[i][j];
			vis[i][j]=0;
		}			
	}


	queue<pair<int,int>>q;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(a[i][j]==1 && !vis[i][j]){
				q.push({i,j});
				vis[i][j]=1;
				cnt=1;
				while(!q.empty()){
					x=q.front().first;
					y=q.front().second;
					q.pop();
				//	cout<<"x"<<" "<<x<<" "<<y<<endl;
					if(x-1>=0 && a[x-1][y]==1 && !vis[x-1][y]){
						q.push({x-1,y});
						vis[x-1][y]=1;
						cnt++;
					}
					if(x+1<n && a[x+1][y]==1 && !vis[x+1][y]){
						q.push({x+1,y});
						vis[x+1][y]=1;
						cnt++;
					}
					if(x-1>=0 && y-1>=0 && a[x-1][y-1]==1 && !vis[x-1][y-1]){
						q.push({x-1,y-1});
						vis[x-1][y-1]=1;
						cnt++;
					}
					if(x+1<n && y-1>=0 && a[x+1][y-1]==1 && !vis[x+1][y-1]){
						q.push({x+1,y-1});
						vis[x+1][y-1]=1;
						cnt++;
					}
					if(x-1>=0 && y+1<m && a[x-1][y+1]==1 && !vis[x-1][y+1]){
						q.push({x-1,y+1});
						vis[x-1][y+1]=1;
						cnt++;
					}
					if(x+1<n && y+1<m && a[x+1][y+1]==1 && !vis[x+1][y+1]){
						q.push({x+1,y+1});
						vis[x+1][y+1]=1;
						cnt++;
					}
					if(y-1>=0 && a[x][y-1]==1 && !vis[x][y-1]){
						q.push({x,y-1});
						vis[x][y-1]=1;
						cnt++;
					}
					if(y+1<m && a[x][y+1]==1 && !vis[x][y+1]){
						q.push({x,y+1});
						vis[x][y+1]=1;
						cnt++;
					}

				}
				maxi=max(maxi,cnt);
				
			}

		}
		
	}
	cout<<maxi<<endl;
	return 0;
}