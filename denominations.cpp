#include<bits/stdc++.h>
using namespace std;

int main() {
	int t,i,n,j,h;
	cin>>t;
	
	int a[10]={2000,500,200,100,50,20,10,5,2,1};
	while(t--){
	    cin>>n;
	    i=0,h=0;
	    int c[n]={0};
	    while(i<10 && n>0){
	        if(a[i]<=n){
	            c[h++]=a[i];
	            n-=a[i];
	            i=0;
	        }
	        else
	            i++;
	    }
	    for(i=0;i<h-1;i++)
	        cout<<c[i]<<" ";
	        cout<<c[h-1]<<endl;
	}
	return 0;
}