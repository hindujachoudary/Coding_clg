#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,i,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int a[100000],s=0;
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   unordered_map<int,vector<int> >c;
	   vector<pair<int,int>>u;
	   for(i=0;i<n;i++){
	       s+=a[i];
	       if(s==0)
	            u.push_back(make_pair(0,i));
	       if(c.find(s)!=c.end()){
	           vector<int>v=c[s];
	           for(auto j=v.begin();j!=v.end();j++)
	                u.push_back(make_pair(*j+1,i));
	       }
	       c[s].push_back(i);
	   }
	   if(u.size()==0)
	   cout<<"No subarray exists"<<endl;
	   else{
	       for(i=0;i<u.size();i++)
	       cout<<"Subarray found from "<<u[i].first<<" "<<"to "<<u[i].second<<endl;
	   }
	}
	return 0;
}
