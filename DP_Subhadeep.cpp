#include<bits/stdc++.h>
using namespace std;

int n,a[2001],dp[1001][1001];
int func(int i,int prev){

    if(i>n-1)
        return 0;

    if(dp[i][prev])
        return dp[i][prev];

    if(a[i] >= prev){
        int mini=2000;
        for(int j=prev;j<=1000;j++)
             mini = min(mini, abs(j-a[i]) + func(i+1, j));
        return dp[i][prev]=mini;
    }

    return dp[i][prev]= ((prev-a[i]) + func(i+1,prev));
}

int main() {
    int t;
    cin>>t;
    while(t--){
	    cin>>n;
	    dp[1001][1001]={0};
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<func(0,1)<<endl;
    }
	return 0;
}
