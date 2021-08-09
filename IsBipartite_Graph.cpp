#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}


bool isBipartite(int a[][MAX],int n){
    int v=1, vis[16]={0};
    for(v = 0; v < n; v++){
        if(vis[v] == 0){
            queue<int>q;
            q.push(v);
            vis[v]=2;
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(int i=0;i<n;i++){
                    if(a[temp][i]==1 && vis[i]==0){
                        q.push(i);
                        vis[i] = 5 - vis[temp];
                    }
                    if(a[temp][i]==1 && vis[i]==vis[temp])
                        return false;
                }
            }
        }
    }
    return true;
}