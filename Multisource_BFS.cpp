#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,n,m,i,j,temp_i,temp_j,temp_c;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    queue< pair <pair <int,int> ,int> >q;
	    char a[1000][1000];
	    int vis[1000][1000]={0};
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>a[i][j];
	   for(i=0;i<n;i++){
	       for(j=0;j<m;j++){
	            if(a[i][j]=='i'){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	            if(a[i][j]=='x')
	                vis[i][j]=1;
	       }
	   }
	   int maxi=0;
	   
	   while(!q.empty()){
	       temp_i=q.front().first.first;
	       temp_j=q.front().first.second;
	       temp_c=q.front().second;
	       q.pop();
	       if(temp_i<n-1 && vis[temp_i+1][temp_j]==0){
	            q.push({{temp_i+1,temp_j},temp_c+1});
	            vis[temp_i+1][temp_j]=1;
	       }
	       if(temp_i>0 && vis[temp_i-1][temp_j]==0){
	            q.push({{temp_i-1,temp_j},temp_c+1});
	            vis[temp_i-1][temp_j]=1;
	       }
	       if(temp_j>0 && vis[temp_i][temp_j-1]==0){
	            q.push({{temp_i,temp_j-1},temp_c+1});
	            vis[temp_i][temp_j-1]=1;
	       }
	       if(temp_j<m-1 && vis[temp_i][temp_j+1]==0){
	            q.push({{temp_i,temp_j+1},temp_c+1});
	            vis[temp_i][temp_j+1]=1;
	        }
	        maxi=max(maxi,temp_c);
	   }
	   int p=0;
	   for(i=0;i<n;i++){
	   	for(j=0;j<m;j++){
	   		if(vis[i][j]==0){
	   			p=-1;
	   			break;
	   		}
	   	}
	   	if(p==-1)
	   		break;
	   }
	   if(p==-1)
	    cout<<-1<<endl;
	   else
	   cout<<maxi<<endl;
	}
	return 0;
}