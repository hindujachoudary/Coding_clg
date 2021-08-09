#include<bits/stdc++.h>
using namespace std;

int a[100000],n,k;
int dp[1000][1000]={0};
int fun(int i,int val){
    if(val==0 && i!=n-1)
        return 1;
    if(i==n-1)
    {
        if((val-a[i])==0 || val==0)
            return 1;
        return 0;
    }
    if(dp[i][val])
        return dp[i][val];
    if((val-a[i])>=0){
        dp[i][val]=fun(i+1,val-a[i])+fun(i+1,val);
        return dp[i][val];}
    dp[i][val]=fun(i+1,val);
    return dp[i][val];
}
int main(){
    int ans,i,t,j;
    cin>>t;
    while(t--){
        ans=0;
        for(i=0;i<1000;i++){
            for(j=0;j<1000;j++){
                dp[i][j]=0;
            }
        }
       cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        cin>>k;
        ans=fun(0,k);
        cout<<ans<<endl;
        }
    return 0;
}