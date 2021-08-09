#include<bits/stdc++.h>
using namespace std;


void swap(int *l,int *m){
    int temp=*l;
    *l=*m;
    *m=temp;
}

int partition1(int a[],int low,int high){
    int pivot=a[low];
    int i=low,j=high+1;
    while(i<j){
        do{
            i++;
        }
        while(a[i]<=pivot);
        do{
            j--;
        }
        while(a[j]>pivot);
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[low],&a[j]);
    return j;
}
int partition2(int a[],int low,int high){
    int pivot=a[low];
    int i=low,j=high;
    while(i<j){
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    swap(&a[low],&a[j]);
    return j;
}




void quicksort(int a[],int low,int high){
    if(low<high){
        int j=partition2(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

void merge(int a[],int c[],int low,int high){
    int i=low;
    int mid=(low+high)/2;
    int k=0,j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j])
            c[k++]=a[i++];
        else 
            c[k++]=a[j++];
        
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++]; 
    for(i=0;i<k;i++)
        a[low+i]=c[i]; 
}


void mergesort(int a[],int low,int high){
    int c[10000];
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,c,low,high); 
    }
}

void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
                swap(&a[j],&a[j+1]);
    
}

void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
    int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini])
                mini=j;
        }
        swap(&a[i],&a[mini]);
    }
}

void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main() {
    int t,i,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[10000];
        for(i=0;i<n;i++)
            cin>>a[i];
        quicksort(a,0,n-1);
        //mergesort(a,0,n-1);
        //bubblesort(a,n);
        //selectionsort(a,n);
        //insertionsort(a,n);
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
    }
	return 0;
}