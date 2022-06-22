#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(N*N)
// Space Complexity: O(1)
void bruteForce(vector<int>& a,int x){
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==x){
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
    }
}


// Time Complexity: O(NlogN) + O(N)
// Space Complexity: O(N)
vector<int> TwoSum(vector<int>& a,int x){
    int n=a.size();
    vector<int> ans,temp;
    temp=a;
    sort(temp.begin(),temp.end());
    int left=0,right=n-1;
    int n1,n2;
    while(left<right){
        if(temp[left]+temp[right]==x){
            n1=temp[left];
            n2=temp[right];
            break;
        }else if(temp[left]+temp[right]>x)
            right--;
        else
            left++;
    }
    for(int i=0;i<n;i++){
        if(a[i]==n1)
            ans.emplace_back(i);
        else if(a[i]==n2)
            ans.emplace_back(i);
    }
    return ans;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
vector<int> hashing(vector<int>& a,int x){
    int n=a.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(x-a[i]) != mp.end()){
            ans.emplace_back(i);
            ans.emplace_back(mp[x-a[i]]);
            break;
            //return ans;
        }else 
            mp[a[i]]=i;
    }
    return ans;
}

int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout<<"Target element: ";int x;cin>>x;
    bruteForce(a,x);
    vector<int> ans=hashing(a,x);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}