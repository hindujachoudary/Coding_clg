#include<bits/stdc++.h>
using namespace std;

//Agressive Cow
long long int cnt,a[1000000],n,dist,h;
int predicate(int k){
    dist=a[0],cnt=1;
    for(int i=1;i<n;i++){
        if((a[i]-dist)>=k){
            cnt++;
            dist=a[i];
        }
        if(cnt==h)
            return 1;
    }
    return 0;
}

int main() {
	long long int t,i;
	cin>>t;
	while(t--){
	    cin>>n>>h;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    sort(a,a+n);
	    long long int low=1,high=a[n-1]-a[0],ans=0;
	    while(low<=high){
	        long long int mid=(low+high)/2;
	        if(predicate(mid)){
	            ans=mid;
	            low=mid+1;
	        }
	        else
	            high=mid-1;
	    }
	    
	   cout<<ans<<endl; 
	}
	return 0;
}
