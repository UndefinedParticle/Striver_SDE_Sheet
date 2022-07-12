#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


// Time Complexity: O(2^n) 
// Each index has two ways. You can either pick it up or not pick it. 
// So for n index time complexity for O(2^n)

// Space Complexity: O(2^n) for storing subset sums, 
// since 2^n subsets can be generated for an array of size n.

void subsetSum(int ind,vector<int> &a,int sum,int n){
    // if(sum==0)
    //     cout<<sum<<" ";
    if(ind==n){
        cout<<sum<<" ";
        return;
    }

    // ds.push_back(a[ind]);
    // sum+=a[ind];

    subsetSum(ind+1,a,sum,n);

    // ds.pop_back();
    // sum-=a[ind];

    subsetSum(ind+1,a,sum+a[ind],n);
    

}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Arrray elements:\n";
    vector<int> a;
    loop(i,0,n){
        int x;cin>>x;
        a.push_back(x);
    }
    cout<<"Subset Sum :\n";
    //vector<int> ds;
    int sum=0;
    subsetSum(0,a,sum,n);
    cout<<endl;





    return 0;
}