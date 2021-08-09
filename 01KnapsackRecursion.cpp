#include<bits/stdc++.h>
using namespace std;

int value[1000],wt[1000],n;
int fun(int i, int remweight){
      
    if(i==n-1){
        if(wt[i]<=remweight)
            return value[i];
        else
            return 0;
    }  
    if(remweight-wt[i]>=0)
        return max(value[i]+fun(i+1,remweight-wt[i]),fun(i+1,remweight));
        
    return fun(i+1,remweight);
    
}


int main(){
    int t,i,j,w;
    cin>>t;
    while(t--){
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