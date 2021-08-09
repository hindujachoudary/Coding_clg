//https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/
// 1 Indexed, left child as 2*i-1, right as 2*i+1;
void max_heapify(int a[], int i, int n){
	int large=i, left=2*i-1, right=2*i+1;
	if(i<n && a[large]<a[left])
		large=left;
	if(i<n && a[large]<a[right])
		large=right;
	swap(a[large], a[i]);
	max_heapify(a, large, n);
}

0(logn) max_heapify

void built_maxheap(int a[], int n){
	for(i=n/2; i>=0; i--)
		max_heapify(a, i, n);
}

0(n) built_maxheap

void heapsort(int a[], int n){
	built_maxheap(a, n);
	swap(a[1], a[n]);
	n-=1;
	for(i=n; i>=1; i--)
		max_heapify(a, 1, n);	
}
0(nlogn) heapsort

