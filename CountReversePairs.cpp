#include<bits/stdc++.h>
using namespace std;


// Time Complexity : O( N log N ) + O (N) + O (N)   
// Reason : O(N) – Merge operation , O(N) – counting operation 
// ( at each iteration of i , j doesn’t start from 0 . 
// Both of them move linearly ) 

// Space Complexity : O(N) 
// Reason : O(N) – Temporary vector
int Merge(vector<int>& a,int low,int mid,int high){
    int totalCount=0;
    int j=mid+1;
    for(int i=low;i<=mid;i++){
        while(j<=high && a[i]>2*a[j])
            j++;
        totalCount=totalCount+(j-(mid+1));
    }
    vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (a[left] <= a[right]) {
      t.push_back(a[left++]);
    } else {
      t.push_back(a[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(a[left++]);
  }
  while (right <= high) {
    t.push_back(a[right++]);
  }

  for (int i = low; i <= high; i++) {
    a[i] = t[i - low];
  }
  return totalCount;
}

int mergeSort(vector<int>& a,int low,int high){
    if(low>=high)
        return 0;
    int mid=(low+high)/2;
    int count=mergeSort(a,low,mid);
    count =count+ mergeSort(a,mid+1,high);
    count=count+Merge(a,low,mid,high);
    return count;
}



int reversePairs(vector<int>& a,int n){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] > 2*a[j])
                count++;
        }
    }
    return count;
}

int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout<<"Ans(1): "<<reversePairs(a,n)<<endl;
    cout<<"Ans(2): "<<mergeSort(a,0,n-1)<<endl;
    return 0;
}