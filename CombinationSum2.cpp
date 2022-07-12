#include<bits/stdc++.h>
using namespace std;

void combinationSum(int ind,vector<int> &a,vector<int> ds,int target,int sum,int n){
    if(ind==n){
        if(target==sum){
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
        }
        
        return;
    }

    
    ds.push_back(a[ind]);
    sum+=a[ind];
    combinationSum(ind+1,a,ds,target,sum,n);

    ds.pop_back();
    sum-=a[ind];
    combinationSum(ind+1,a,ds,target,sum,n);



}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    cout<<"Target: ";int t;cin>>t;
    cout<<"Ans:\n";
    vector<int> ds;
    combinationSum(0,a,ds,t,0,n);








    return 0;
}