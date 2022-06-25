#include<bits/stdc++.h>
using namespace std;

int xorK(vector<int>& a,int n,int k){
    int count=0;
    for(int i=0;i<n;i++){
        int xor1=0;
        // int xor1=a[i];
        // if(xor1==k)
        //     count++;
        for(int j=i;j<n;j++){
            xor1=xor1^a[j];
            if(xor1==k)
                count++;
        }
    }
    return count;
}

int countXor(vector<int>& a,int n,int k){
    unordered_map<int,int> mp;
    int count=0;
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^a[i];
        if(xor1==k){
            count++;
        
        }
        if(mp.find(xor1^k)!=mp.end()){
            count=count+mp[xor1^k];
        }
        mp[xor1]++;
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
    cout<<"Value of K:";int k;cin>>k;
    cout<<"Number of subarrays with given XOR K: "<<xorK(a,n,k)<<endl;
    cout<<"Number of subarrays with given XOR K: "<<countXor(a,n,k)<<endl;



    return 0;
}