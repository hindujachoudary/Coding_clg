#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,k,z=0;
    cin>>n;
    int b[n],a[n],count[101]={0},s=0,c=0;
    for(i=0;i<n;i++)
        cin>>b[i];
    for(i=0;i<n;i++)
        count[b[i]]++;
    set<int>st;
    for(i=0;i<n;i++)
        st.insert(b[i]);
    for(auto x:st)
        a[z++]=x;
    for(i=0;i<z;i++){
        for(j=0;j<z;j++){
            for(k=max(i,j);k<z;k++){
                s=a[i]+a[j]+a[k];
                if(a[i]!=a[j] && a[j]!=a[k] && a[i]!=a[k]){ 
                    if((s%a[i]!=0) && (s%a[j]!=0) && (s%a[k]==0))
                        c+=count[a[i]]*count[a[j]]*count[a[k]];
                    if((s%a[i]!=0) && (s%a[j]==0) && (s%a[k]!=0))
                        c+=count[a[i]]*count[a[j]]*count[a[k]];
                    if((s%a[i]==0) && (s%a[j]!=0) && (s%a[k]!=0))
                        c+=count[a[i]]*count[a[j]]*count[a[k]];
                }
            
            if(a[i]==a[k] && a[i]!=a[j])
                if(s%a[j]==0 && s%a[i]!=0)
                    c+=count[a[j]]*count[a[i]]*(count[a[i]]-1)/2;
            if(a[i]==a[j] && a[i]!=a[k])
                if(s%a[k]==0 && s%a[i]!=0)
                    c+=count[a[k]]*count[a[i]]*(count[a[i]]-1)/2;
            if(a[j]==a[k] && a[j]!=a[i])
                if(s%a[i]==0 && s%a[j]!=0)
                    c+=count[a[i]]*count[a[j]]*(count[a[j]]-1)/2;
            }
        }
    }
cout<<3*c<<endl;
return 0;   
}
