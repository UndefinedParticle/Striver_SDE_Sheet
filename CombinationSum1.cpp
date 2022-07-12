#include<bits/stdc++.h>
using namespace std;

void combinationSum(int ind,vector<int> &a,vector<int> ds,int target,int n){
    if(ind==n){
        if(target==0){
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
            
        }
        return;
    }

    if(a[ind]<=target){
        ds.push_back(a[ind]);
        combinationSum(ind,a,ds,target-a[ind],n);
        ds.pop_back();
    }
    combinationSum(ind+1,a,ds,target,n);



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
    combinationSum(0,a,ds,t,n);








    return 0;
}