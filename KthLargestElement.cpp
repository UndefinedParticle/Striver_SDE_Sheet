#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

// Time complexity: O(nlogn)
// Space complexity: O(1)
int KthElement1(vector<int> &a,int k){
    sort(a.begin(),a.end());

    return a[a.size()-k];
}


// Time complexity: O(k+(n-k)*log(k))  , n = size of array
// Space complexity: O(k)
int KthElement2(vector<int> &a,int k){
    priority_queue<int> pq;
    int n=a.size();
    loop(i,0,n){
        pq.push(a[i]);
    }

    int t=k-1;
    while(t){
        pq.pop();
        t--;
    }
    return pq.top();
}

int partition(vector<int> &a,int left,int right){

    int pivot=a[left];
    int l=left+1,r=right;
    while(l<=r){
        if(a[l]<pivot && a[r]>pivot){
            swap(a[l],a[r]);
            l++;
            l--;
        }

        if(a[l]>=pivot){
            l++;
        }
        if(a[r]<=pivot){
            r--;
        }
    }
    swap(a[left],a[right]);
    

    return r;
}

int KthElement3(vector<int> &a,int k){

    int n=a.size();
    int left=0,right=n-1,Kth;

    while(1){
        int index=partition(a,left,right);
        if(index==k-1){
            Kth=a[index];
            break;
            if(index < k-1){
                left=index+1;
            }else{
                right=index-1;
            }
        }
    }   


    return Kth;
}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a(n);
    loop(i,0,n){
        cin>>a[i];
    }
    cout<<"Value of K: ";int k;cin>>k;
    cout<<k<<"-th largest element: "<<KthElement1(a,k)<<endl;
    cout<<k<<"-th largest element: "<<KthElement2(a,k)<<endl;



    return 0;
}