#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define rloop(i,n,a) for(int i=n;i>=a;i--)
#define all(a) a.begin(),a.end()
/*
vector<vector<int>> printPermutation(vector<int> &a,int fact,int n){
    vector<vector<int>> ans;
    ans.push_back(a);
    loop(k,1,fact){
        int i,j;
        for(i=n-2;i>=0;i--){
            if(a[i]<a[i+1])
                break;
        }

        if(i<0)
            reverse(all(a));
        else{
            for(j=n-1;j>i;j--){
                if(a[j]>a[i])
                    break;
            }
            swap(a[i],a[j]);
            reverse(a.begin()+i+1,a.end());
        }
        ans.push_back(a);
    }

    return ans;
    
}


// Time Complexity:  O(N! x N)
// Space Complexity:  O(N)
vector<vector<int>> recurPermutation(vector<int> &a,vector<int> ds,vector<vector<int>> &ans,int freq[],int n){
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }

    loop(i,0,n){
        if(freq[i]==0){
            ds.push_back(a[i]);
            freq[i]=1;
            recurPermutation(a,ds,ans,freq,n);
            freq[i]=0;
            ds.pop_back();
        }
    }


    return ans;


}*/


// Time Complexity: O(N! X N)
// Space Complexity: O(1)
void getPermutation(int ind,vector<int> &a,int n){
    if(ind==n){
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }cout<<endl;
        return;
    }

    for(int i=ind;i<n;i++){
        swap(a[ind],a[i]);
        getPermutation(ind+1,a,n);
        swap(a[ind],a[i]);
    }
}








int main(){


    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    //int fact=1;
    loop(i,0,n){
        //fact = fact*(i+1);
        int x;cin>>x;
        a.push_back(x);
    }

    cout << "All Permutations are:" << endl;
    getPermutation(0,a,n);
    





    return 0;
}