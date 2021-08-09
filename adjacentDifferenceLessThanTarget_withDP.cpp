#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,m,n,i,j,x,y,len, ans;
	cin>>t;
	while(t--){
	    int maxi=0;
	    cin>>m>>n;
	    int a[1000][1000];
	    for(i=0;i<m;i++){
	        for(j=0;j<n;j++)
	            cin>>a[i][j];
	    }
	    int dp[1000][1000];
	    dp[0][0]=a[0][0];
	    for(i=0;i<m;i++){
	        for(j=0;j<n;j++){
	            if(j==0)
	                dp[i][0]=dp[i-1][0]+a[i][0];
	            else if(i==0)
	                dp[0][j]=dp[0][j-1]+a[0][j];
	           else
	               dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
	            }
	    }
	    
	    for(i=0;i<m;i++){
	        for(j=0;j<n;j++){
	            if(a[i][j]==1){
	                int low = 1;
	                int high = min(m-i,n-j);
	                while(low<=high){
	                    len = (low+high)/2;
	                    int flag = 0;
	                    int sum=dp[i+len-1][j+len-1]-dp[i+len-1][j-1]-dp[i-1][j+len-1]+dp[i-1][j-1];
	                    if(sum==(len*len))
	                        flag=0;
	                    else
	                        flag=1;
                        if(flag==1)
    	                    high = len-1;
    	                else{
    	                    low = len+1;
    	                    ans = len;
    	                }
    	           }
    	           maxi = max(maxi, ans);
    	       }
	       }
	   }
	   cout<<maxi<<endl;
	}
	return 0;
}