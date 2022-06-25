#include<bits/stdc++.h>
using namespace std;

/*int merge_(int a[],int temp[],int left,int mid,int right){
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
}*/

int Merge(int a[],int left,int mid,int right){
    int count=0;
    int n1=mid-left+1;
    int n2=right-mid;
    int b[n1],c[n2];
    for(int i=0;i<n1;i++){
        b[i]=a[left+i];
    }
    for(int i=0;i<n2;i++){
        c[i]=a[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2){
        if(b[i]<=c[j]){
            a[k]=b[i];
            //cout<<a[k]<<" ";
            k++,i++;
        }else{
            a[k]=c[j];
            //cout<<a[k]<<" ";
            k++,j++;
            count=count+(n1-i);
            
        }
    }
    while(i<n1)
        a[k++]=b[i++];
    while(j<n2)
        a[k++]=c[j++];


    //cout<<count<<" ";


    return count;

}

int mergeSort(int a[],int left,int right){
    int mid,count=0;
    if(right>left){
        mid=(right+left)/2;
        count+=mergeSort(a,left,mid);
        count+=mergeSort(a,mid+1,right);
        count+=Merge(a,left,mid,right);
    }
    
    return count;
}

/*int mergeSort_(int a[],int temp[],int left,int right){
    int mid,count=0;
    if(right>left){
        mid=(right+left)/2;
        count+=mergeSort_(a,temp,left,mid);
        count+=mergeSort_(a,temp,mid+1,right);
        count+=merge_(a,temp,left,mid+1,right);
    }
    return count;
}*/
int main(){

    cout<<"Array Size:";
    int n;cin>>n;
    cout<<"Array Elements:\n";
    int a[n];//,temp[n];
    //vector<int> a;
    for(int i=0;i<n;i++){
        cin>>a[i];
        //int x;cin>>x;
        //a.emplace_back(x);
    }
    //vector<int> temp;
    // int ans=mergeSort_(a,temp,0,n-1);
    // cout<<"The total inversions are "<<ans<<endl; 

    int ans1=mergeSort(a,0,n-1);
    cout<<"The total inversions are "<<ans1<<endl;

    return 0;
}