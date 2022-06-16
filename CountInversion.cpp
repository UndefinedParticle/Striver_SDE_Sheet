#include<bits/stdc++.h>
using namespace std;

int merge_(int a[],int temp[],int left,int mid,int right){
    int count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i<=mid-1) && (j<=right)){
        if(a[i]<=a[j]){
            temp[k++]=a[i++];
        }else{
            temp[k++]=a[j++];
            count=count+(mid-i);

        }
    }
    while(i<=mid-1)
        temp[k++]=a[i++];
    while(j<=right)
        temp[k++]=a[j++];
    for(i=left;i<=right;i++){
        a[i]=temp[i];
    }
    return count;
}

int mergeSort(int a[],int temp[],int left,int right){
    int mid,count=0;
    if(right>left){
        mid=(right+left)/2;
        count+=mergeSort(a,temp,left,mid);
        count+=mergeSort(a,temp,mid+1,right);
        count+=merge_(a,temp,left,mid+1,right);
    }
    return count;
}

int main(){

    cout<<"Array Size:";
    int n;cin>>n;
    cout<<"Array Elements:\n";
    int a[n],temp[n];
    //vector<int> a;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //int x;cin>>x;
        //a.emplace_back(x);
    }
    //vector<int> temp;
    int ans=mergeSort(a,temp,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 

    return 0;
}