#include <bits/stdc++.h>
using namespace std;

struct val{
    int first;
    int second;
};

bool compare(val a,val b){
    return a.second<b.second;
}

int main() {
	int t,n,i;
	cin>>t;
	while(t--){
	    cin>>n;
	    struct val p[n];
	    for(i=0;i<n;i++)
	        cin>>p[i].first;
	   for(i=0;i<n;i++)
	    cin>>p[i].second;
	    sort(p,p+n,compare);
	    //for(i=0;i<n;i++)
	     //   cout<<p[i].first<<" "<<p[i].second<<"  ";
	   int x=0,c=1,i=1;
	    while(i<n){
	        if(p[x].second <= p[i].first){
	            c+=1;
	            x=i;
	        }
	        i+=1;
	    }
	    cout<<c<<endl;
	}
	return 0;
}