#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int dp[1000][1000];
int func(int i,int j){
    if(i>=j)
        return 0;
    if(dp[i][j])
        return dp[i][j];
    if(s[i]==s[j])
        return dp[i][j]=func(i+1,j-1);
    else
        return dp[i][j]=1+min(func(i,j-1),func(i+1,j));
}

int main() {
	int t,k;
	cin>>t;
	while(t--){
	    cin>>s;
	    
	    memset(dp,0,sizeof(dp));
	    n=s.length();
	    k=func(0,n-1);
	    cout<<k<<endl;
	}
	return 0;
}