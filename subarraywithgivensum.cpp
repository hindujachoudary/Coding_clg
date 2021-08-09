
int main() {
	int t,n,i,j,s,k,flag;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    int a[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
	    i=0,j=0,s=0,flag=0;
	    while(i<n){
	       if(s==k){
	           flag=1;
	           break;
	       }
	       if(s>k){
	           s-=a[i];
	           i+=1;
	       }
	       if(s<k){
	           s+=a[j];
	        j+=1;}
	   }
	   if(flag==1)
	        cout<<i+1<<" "<<j<<endl;
	   else
	    cout<<-1<<endl;
	   
	}
	return 0;
}