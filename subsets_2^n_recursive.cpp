#include<bits/stdc++.h>
using namespace std;

vector<string>v;
vector<string> subsets(int i, string ans){

	//base
	if(i==n)
		v.push_back(ans);
	subsets(i+1, s[i]+ans);
	subsets(i+1, ans);

}


int main(){
	string s, ans='';
	cin>>s;
	int n=s.length(), i;
	string a[100];
	subsets(-1,ans);

	
	return 0;
}