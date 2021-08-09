#include<bits/stdc++.h>
using namespace std;

int n,k,p;
int func(int i,int loc,int prev,int k,int p){
	if(i==n){
		if(k==0 && i-prev<=p)
			return 1;
		else
			return 0;
	}
	if(i-prev > p)
		return 0;
	int ans=0;
	if(loc==-1){
		ans+=func(i+1,0,prev,k-1,p);
		ans+=func(i+1,1,prev,k-1,p);
		ans+=func(i+1,2,prev,k-1,p);
		ans+=func(i+1,3,prev,k-2,p);

	}
	if(loc==0){
		ans+=func(i+1,-1,prev,k,p);
		ans+=func(i+1,1,prev,k-1,p);
		ans+=func(i+1,2,prev,k-1,p);
	}
	if(loc==1){
		ans+=func(i+1,-1,prev,k,p);
		ans+=func(i+1,0,prev,k-1,p);
		ans+=func(i+1,2,prev,k-1,p);
		ans+=func(i+1,3,prev,k-2,p);
	}
	if(loc==2){
		ans+=func(i+1,-1,prev,k,p);
		ans+=func(i+1,0,prev,k-1,p);
		ans+=func(i+1,1,prev,k-1,p);
	}
	if(loc==3){
		ans+=func(i+1,-1,prev,k,p);
		ans+=func(i+1,1,prev,k-2,p);
	}


	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>k;
		cin>>p;
		cout<<func(-1,-1,-1,k,p);

	}

return 0;	
}