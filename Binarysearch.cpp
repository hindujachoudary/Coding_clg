int predicate(k) {
	i=n-k;
	j=0;
	flag = 1;
	for(j=0;j<k;j++)
		if(a[i]<=b[j]){
			flag = 0;
			break;
		}
	return flag;
}
int low=0,high=n;
int ans=-1;
while(low<=high){
	int mid = (low+high)/2;
	if(predicate(mid)){
		ans=mid;
		low=mid+1;
	}
	else{
		high=mid-1;
	}
}
cout << ans;





subsequences of lenth c 
in eveery subsequence minimum diff is ans
try to maximise the ans
naive approach

nakento dp laga anipistundi binary search kosam try chestunte



y y y y y y y y y y y y y y n n n n n n

0 0 0 0 0 2 3 

1 2 3 0 0 0 0

