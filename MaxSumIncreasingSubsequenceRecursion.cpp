#include<bits/stdc++.h>
using namespace std;

int value[1000],n;
int fun(int i, int val){
    if(i==n-1){
        if(value[i]>val)
            return value[i];
        else
            return 0;
    }  
    if(value[i]>val)
        return max(value[i]+fun(i+1,value[i]),fun(i+1,val));
    return fun(i+1,val);
    
}


int main(){
    int t,i,j,w;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>value[i];
        int ans=0;
        ans=fun(0,0);
        cout<<ans<<endl;
        
    }
    return 0;
}