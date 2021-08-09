#include <bits/stdc++.h>
using namespace std;

struct val{
    int start;
    int end;
    int pos;
};
 bool compare(val a,val b){
     return a.end<b.end;
 }
 
int main() {
	int t,i,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    struct val p[n];
	    for(i=0;i<n;i++)
	        cin>>p[i].start;
	   for(i=0;i<n;i++){
	       cin>>p[i].end;
	       p[i].pos=i+1;
	   }
	   sort(p,p+n,compare);
	   int x=0,h=1,b[n];
	   i=0;
	   b[0]=p[0].pos;
	   while(i<n){
	       if(p[x].end < p[i].start){
	           b[h++]=p[i].pos;
	           x=i;
	       }
	       i++;
	        
	   }
	 for(i=0;i<h-1;i++)
	    cout<<b[i]<<" ";
	    cout<<b[h-1]<<endl;
	}
	return 0;
}