#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,i,n,p,j;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		if(n==1)
			cout<<1<<endl;
		else if(n==2)
			cout<<2<<endl;
		else{
			a[0]=0;
			a[1]=0;
			int c[129];
			c[0]=2;
			for(i=1;i<=128;i++)	
				c[i]=-1;

			for(i=2;i<n;i++){
				p=0;
				if(c[a[i-1]]>1){
					for(j=i-2;j>=0;j--){
						if(a[j]==a[i-1]){
							p=j;
							break;
						}
					}
					a[i]=i-1-p;
				}
				else
					a[i]=0;
				c[a[i]]++;
			}
			cout<<c[a[n-1]]<<endl;
		}
	}
	return 0;
}