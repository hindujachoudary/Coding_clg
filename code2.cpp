#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,p,temp,i,j;
	string s;
	cin>>n;
	cin>>s;
	int a[10][10];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++)
			cin>>a[i][j];
	}
	int h=0;
	int b[65],c[65];
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(a[i][j]==s[0]){
				b[h++]=i;
				c[h++]=j;
			}
		}
	}

	int d;
	int count=0;
	for(d=0;d<h;d++){
		p=0;
		i=b[d],j=c[d];
		//while(p<n){
		//	if(a[i][j]==s[p]){
				queue<int>q;
				p++;

				q.push(p);
				while(!q.empty() && p<n){
					temp=q.front();
					q.pop();
					if(j!=7 && a[i][j+1]==s[temp]){
						p++;
						q.push(p);
					}
					if(j!=0 && a[i][j-1]==s[temp]){
						p++;
						q.push(p);
					}
					if(i!=0 && j!=0 && a[i-1][j-1]==s[temp]){
						p++;
						q.push(p);
					}
					if(i!=0 && a[i-1][j]==s[temp]){
						p++;
						q.push(p);
					}
					if(i!=0 && j!=7 && a[i-1][j+1]==s[temp]){
						p++;
						q.push(p);
					}
					if(i!=7 && j!=0 && a[i+1][j-1]==s[temp]){
						p++;
						q.push(p);
					}
					if(i!=7 && a[i+1][j]==s[temp]){
						p++;
						s.push(p);
					}
					if(i!=7 && j!=7 && a[i+1][j+1]==s[temp]){
						p++;
						s.push(p);
					}
			}
			count++;
		}
	return 0;
}