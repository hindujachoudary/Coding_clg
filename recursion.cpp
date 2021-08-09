#include<bits/stdc++.h>
using namespace std;

char a[10][10];
int vis[10][10];
string s;
int n;
int func(int i,int j,int p){
	int h=0;
	if(p==n-1 && a[i][j]==s[p])
		return 1;
	if(i==-1 || j==-1 || i==8 || j==8)
		return 0;
    if(p==n-1 && a[i][j]!=s[p])
        return 0;
   	vis[i][j]=1;
	if(a[i][j]==s[p]){
			if(j!=7 && vis[i][j+1]==0)
				h+=func(i,j+1,p+1);
			if(j!=0 && vis[i][j-1]==0)
				h+=func(i,j-1,p+1);
			if(i!=7 && j!=0 && vis[i+1][j-1]==0)
				h+=func(i+1,j-1,p+1);
			if(i!=7 && vis[i+1][j]==0)
				h+=func(i+1,j,p+1);
			if(i!=7 && j!=7&& vis[i+1][j+1]==0)
				h+=func(i+1,j+1,p+1);
			if(i!=0 && j!=0 && vis[i-1][j-1]==0)
				h+=func(i-1,j-1,p+1);
			if(i!=0 && vis[i-1][j]==0)
				h+=func(i-1,j,p+1);
			if(i!=0 && j!=7 && vis[i-1][j+1]==0)
				h+=func(i-1,j+1,p+1);
	}
	vis[i][j]=0;
	return h;
}

int main(){
	int k,i,j;
	cin>>n;
	cin>>s;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++)
			cin>>a[i][j];
	}
	int t=0,m=0,b[64],c[64];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(a[i][j]==s[0]){
				b[t++]=i;
				c[m++]=j;
			}
		}
	}
	int ans=0;
	for(i=0;i<t;i++)
		ans+=func(b[0],c[0],0);
	cout<<ans<<endl;
	return 0;
}
