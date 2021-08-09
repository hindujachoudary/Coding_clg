#include <bits/stdc++.h>
using namespace std;
int n,x,y,z,dp[40001];
int func(int k){
    if(k==0)
        return 1;
    if(k<0)
        return 0;
    if(dp[k]!=-1)
        return dp[k];
   int l=max(func(k-z),max(func(k-x),func(k-y)));
    if(l==0)
        dp[k]=0;
    else
        dp[k]=l+1;
    return dp[k];
}

int main() {
	int t,ans;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
	    cin>>n;
	    cin>>x>>y>>z;
	    ans=func(n);
	    cout<<ans-1<<endl;
	}
	return 0;
}