#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int main(){
    long long int t,i,s;
    cin>>t;
    while(t--){
        cin>>n;
        vector<long long int>a(n),h(n),x(n);
        for(i=0;i<n;i++)
            cin>>x[i]>>h[i];
        
        sort(h.begin(),h.end());
        a.push_back(x[1]-x[0]);
        for(i=1;i<n-1;i++)
            a.push_back(x[i+1]-x[i-1]);
        a.push_back(x[n-1]-x[n-2]);
    
        sort(a.begin(),a.end());
        for(i=0;i<n;i++)
            s+=a[i]*h[i];
        cout<<s<<endl;
    }
    return 0;
}