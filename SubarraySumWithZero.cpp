#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*N) as we have two loops for traversal
// Space Complexity : O(1) as we aren’t using any extra space.
int subArraySum(vector<int>& a,int n){
    int sum;
    int length=0;
    int maxi=0;
    for(int i=0;i<n;i++){
        sum=0;
        length=0;
        for(int j=i;j<n;j++){
            sum=sum+a[j];
            length++;
            if(sum==0){
                maxi=max(maxi,length);
            }
            
        }
    }
    return maxi;
}


// Time Complexity: O(N), as we are traversing the array only once
// Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
int maxLength(vector<int>& a,int n){
    unordered_map<int,int> mp;
    int maxi=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum +=a[i];
        if(sum==0)
            maxi=i+1;
        else{
            if(mp.find(sum) != mp.end())
                maxi=max(maxi,i-mp[sum]);
            else
                mp[sum]=i;
        }
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
    cout<<"Longest length: "<<subArraySum(a,n)<<endl;
    cout<<"Longest length: "<<maxLength(a,n)<<endl;


    return 0;
}