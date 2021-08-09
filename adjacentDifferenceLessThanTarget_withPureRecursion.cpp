#include<bits/stdc++.h>
using namespace std;
int target, n, a[1000];
int func(int i,int val){
    if(i==n-1)
        return abs(val-a[i]);
    int mini=99999;
    for(int p=-target;p<=target;p++){
        if(val+p>=0)
            mini=min(mini,func(i+1,val+p));
    }
    return mini+abs(a[i]-val);
}

int main() {
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	    cin>>a[i];
	cin>>target;
	int mini=999999;
	for(j=0;j<101;j++)
	    mini=min(mini,func(0,j));
	cout<<mini<<endl;
	return 0;
}