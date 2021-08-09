#include<bits/stdc++.h>
using namespace std;




int vis[1000][1000],n,a[1000][1000],h=INT_MAX;
int func(int i,int j){
    vis[i][j]=1;
    if(i==n-1 && j==n-1)
        return a[i][j];

    if(i!=n-1 && vis[i+1][j]!=1)
         h=min(h,func(i+1,j));
    if(i>0 && vis[i-1][j]!=1)
         h=min(h,func(i-1,j));
    if(j>0 && vis[i][j-1]!=1)
         h=min(h,func(i,j-1));
    if(j!=n-1 && vis[i][j+1]!=1)
         h=min(h,func(i,j+1));

    return a[i][j]+ h;

    vis[i][j]=0;
}


int main() {
	int t,b,i,j;
	cin>>t;
	while(t--){
	    cin>>n;
	    for(i=0;i<n;i++)
	        for(j=0;j<n;j++)
	            cin>>a[i][j];

	   cout<<func(0,0)<<endl;

	}
	return 0;
}
