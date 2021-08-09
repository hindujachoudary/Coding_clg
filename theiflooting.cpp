#include<bits/stdc++.h>
using namespace std;
int a[10001],n,dp[10001];
int func(int i){
    if(i>=n)
        return 0;
    if(i==n-1)
        return a[i];
    if(dp[i])
        return dp[i];
    return dp[i]=max(a[i]+func(i+2),func(i+1));
}
int main() {
	int t,i;
	cin>>t;
	while(t--){
	    memset(dp,0,sizeof(dp));
	    cin>>n;
	   //cout<<n<<endl;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   cout<<func(0)<<endl;
	}
	return 0;
}