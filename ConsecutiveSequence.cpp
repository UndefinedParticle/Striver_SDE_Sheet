#include<bits/stdc++.h>
using namespace std;

int longestSequence(vector<int>& a,int n){
    if(a.empty())
        return 0;
    sort(a.begin(),a.end());
    int count=1,maxi=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]+1){
            count++;
        }else if(a[i]==a[i-1])
            continue;
        else
            count=1;
        maxi=max(maxi,count);
    }
    return maxi;
}


int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }

    cout<<"Ans(1): "<<longestSequence(a,n)<<endl;



    return 0;
}