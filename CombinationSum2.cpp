#include<bits/stdc++.h>
using namespace std;


void combinationSum1(int ind,vector<int> &a,vector<int> ds,set<vector<int>> &ans,int target,int n){
    if(ind==n){
        if(target==0){
            ans.insert(ds);
            
        }
        return;
    }

    if(a[ind]<=target){
        ds.push_back(a[ind]);
        combinationSum1(ind+1,a,ds,ans,target-a[ind],n);
        ds.pop_back();
    }
    combinationSum1(ind+1,a,ds,ans,target,n);



}


// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n).
// we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k 
// where k is the average length of the combination
void combinationSum2(int ind,vector<int> &a,vector<int> ds,int target,int n){
    //if(ind==n){
        if(target==0){
            for(auto it: ds)
                cout<<it<<" ";
            cout<<endl;
            return;
        }
        
    //}

    for(int i=ind;i<n;i++){
        if(i>ind && a[i]==a[i-1])
            continue;
        if(a[i]>target)
            break;
        ds.push_back(a[i]);
        combinationSum2(i+1,a,ds,target-a[i],n);
        ds.pop_back();
    }
    


}



int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    cout<<"Target: ";int t;cin>>t;
    cout<<"Ans:\n";
    vector<int> ds;
    combinationSum2(0,a,ds,t,n);








    return 0;
}