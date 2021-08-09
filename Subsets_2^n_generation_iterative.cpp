#include<bits/stdc++.h>
using namespace std;

int main(){
	string s, ans='';
	cin>>s;
	int n=s.length(), i;
	string a[100];
	for(i=0; i<pow(2,n); i++){
		ans='';

		//for each counter (0 to 2^(n-1))

		for(j=0; j<n; j++){

			//check if the counter's bit is set or not 
			//if bit is set ((i & 2^j)==1) then include s[j] else don't include
			if(i & 1<<j)
				ans+=s[j];
		}
		a[i]=ans;
	}
	return 0;
}