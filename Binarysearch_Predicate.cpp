#include<bits/stdc++.h>
using namespace std;

//codechef ceil qstn
//codechef.com/MINEAT
long long int h,a[1000000],n;
int predicate(int k){
    long long int s=0;
   for(long long int i=0;i<n;i++){
       if(a[i]%k==0)
            s+=a[i]/k;
        else
            s+=(a[i]/k)+1;
   } 
   if(s<=h)
        return 1;
    else
        return 0;
    
}

int main() {
	long long int t,i;
	cin>>t;
	while(t--){
	    cin>>n>>h;
	    long long int maxi=0;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        maxi=max(maxi,a[i]);
	    }
	    
	    long long int low=1,high=maxi,ans=0;
	    while(low<=high){
	        long long int mid=(low+high)/2;
	        if(predicate(mid)){
	            ans=mid;
	            high=mid-1;
	        }
	        else
	            low=mid+1;
	    }
	    
	   cout<<ans<<endl; 
	}
	return 0;
}
