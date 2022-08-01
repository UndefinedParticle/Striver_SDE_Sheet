#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

// Time Complexity :We iterate at total k times. 
// This makes time complexity to O(k)

// Space Complexity :O(1)
int kthElement(vector<int> &arr1,vector<int> &arr2,int k){
    int m=arr1.size();
    int n=arr2.size();

    int cnt=0;
    int left=0,right=0;
    while(left<m && right<n){
        if(arr1[left]<=arr2[right]){
            cnt++;
            if(cnt==k){
                return arr1[left];
            }
            left++;
        }else{
            cnt++;
            if(cnt==k){
                return arr2[right];
            }
            right++;
        }
    }
    while(left<m){
        cnt++;
        if(cnt==k){
            return arr1[left];
        }
        left++;
    }
    while(right<n){
        cnt++;
        if(cnt==k){
            return arr2[right];
        }
        right++;
    }

    return -1;

}


// Time Complexity : log(min(m,n))
// Space Complexity: O(1)
int kthElement1(vector<int> &arr1,vector<int> &arr2,int k){
    int m=arr1.size();
    int n=arr2.size();

    if(m>n){//ensuring that binary search happens on minimum size array
        vector<int> temp=arr1;
        arr1=arr2;
        arr2=temp;
        int x=m;
        m=n;
        n=x;
    }

    int low=max(0,k-n),high=min(k,m);
    while(low<=high){
        int cut1=(low+high)>>1;
        int cut2=k-cut1;
        int l1=(cut1==0)? INT_MIN:arr1[cut1-1];
        int l2=(cut2==0)? INT_MIN:arr2[cut2-1];
        int r1=(cut1==m)? INT_MAX:arr1[cut1];
        int r2=(cut2==n)? INT_MAX:arr2[cut2];
        if(l1<=r2 && l2<=r1){
            return max(l1, l2);
        }else if(l1>r2){
            high=cut1-1;
        }else{
            low=cut1+1;
        }
    }

    return -1;
}


int main(){

    cout<<"Array1 size: ";int m;cin>>m;
    cout<<"Array1 Elements:\n";
    vector<int> arr1;
    loop(i,0,m){
        int x;cin>>x;
        arr1.emplace_back(x);
    }

    cout<<"Array2 size: ";int n;cin>>n;
    cout<<"Array2 Elements:\n";
    vector<int> arr2;
    loop(i,0,n){
        int x;cin>>x;
        arr2.emplace_back(x);
    }

    cout<<"K-th Postion: ";int k;cin>>k;
    
    cout<<"The element at the kth position in the final sorted array is: "<<kthElement(arr1,arr2,k)<<endl;
    cout<<"The element at the kth position in the final sorted array is: "<<kthElement1(arr1,arr2,k)<<endl;







    return 0;
}