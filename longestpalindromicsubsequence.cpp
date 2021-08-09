#include <bits/stdc++.h>
using namespace std;
string s,y;
int dp[1000][1000];
int func(int i,int j){
    if(i==0 || j==0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i-1]==y[j-1])
        return dp[i][j]=1+func(i-1,j-1);
    return dp[i][j]=max(func(i-1,j),func(i,j-1));
}

int main() {
	int i,t,ans;
	cin>>t;
	while(t--){
	    memset(dp,-1,sizeof(dp));
	    cin>>s;
	    y=s;
	    reverse(y.begin(),y.end());
	  ans=func(s.length(),s.length());
	   cout<<ans<<endl;
	}
	return 0;
}
