#include<bits/stdc++.h>
using namespace std;

int n,k,p,dp[100][5][10][100];
int func(int i,int loc,int prev,int k){
    
	if(i==n){
		if(k==0 && i-prev<=p)
			return 1;
		else
			return 0;
	}
	
	if(i-prev > p)
		return 0;
	
	if(dp[i][loc][prev][k]!=-1)
	    return dp[i][loc][prev][k];
	int ans = func(i+1, 4, prev, k);
	if(loc == 3)
	    ans += func(i+1, 1, i, k-1);
	else{
    	for(int j = 0; j < 3; j++)
    	    if(j != loc)
    	        ans += func(i+1, j, i, k-1);
    	if(loc == 2 || loc == 4)
    	    ans += func(i+1, 3, i, k-2);
	}
	return ans;
// 	int ans=0;
// 	if(loc==4){
// 	    ans+=func(i+1,4,prev,k);
// 		ans+=func(i+1,0,i,k-1);
// 		ans+=func(i+1,1,i,k-1);
// 		ans+=func(i+1,2,i,k-1);
// 		ans+=func(i+1,3,i,k-2);

// 	}
// 	if(loc==0){
// 		ans+=func(i+1,4,prev,k);
// 		ans+=func(i+1,1,i,k-1);
// 		ans+=func(i+1,2,i,k-1);
// 	}
// 	if(loc==1){
// 		ans+=func(i+1,4,prev,k);
// 		ans+=func(i+1,0,i,k-1);
// 		ans+=func(i+1,2,i,k-1);
// 		ans+=func(i+1,3,i,k-2);
// 	}
// 	if(loc==2){
// 		ans+=func(i+1,4,prev,k);
// 		ans+=func(i+1,0,i,k-1);
// 		ans+=func(i+1,1,i,k-1);
// 	}
// 	if(loc==3){
// 		ans+=func(i+1,4,prev,k);
// 		ans+=func(i+1,1,i,k-2);
// 	}
// 	return dp[i][loc][prev][k]=ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
		cin>>n;
		cin>>k;
		cin>>p;
		cout<<func(0,4,-1,k);
	}

return 0;	
}