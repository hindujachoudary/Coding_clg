#include <bits/stdc++.h>
using namespace std;
int value[10000],wt[10000],n,dp[1001][1001];
int fun(int i, int remweight){
    if(i==n-1){
        if(wt[i]<=remweight)
            return value[i];
        else
            return 0;
    }  
    if(dp[i][remweight])
        return dp[i][remweight];

    if(remweight-wt[i]>=0){
        dp[i][remweight]=max(value[i]+fun(i+1,remweight-wt[i]),fun(i+1,remweight));
        return dp[i][remweight];
    }
    dp[i][remweight]=fun(i+1,remweight);
    return dp[i][remweight];
    
}


int main(){
    int t,i,j,w;
    cin>>t;
    while(t--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        cin>>w;
        for(i=0;i<n;i++)
            cin>>value[i];
        for(i=0;i<n;i++)
            cin>>wt[i];
        int ans=0;
        ans=fun(0,w);
        cout<<ans<<endl;
        
    }
    return 0;
}