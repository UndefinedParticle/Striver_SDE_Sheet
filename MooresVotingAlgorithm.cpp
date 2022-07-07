#include<bits/stdc++.h>
using namespace std;

int method3(vector<int>& arr,int size){
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            count =1;
            return i.first;
            break;
        }
    }
    if(count == 0)
        return -1;
}

    // Time Complexity: O(N)
    // Space Complexity: O(1)
int majorityElement(vector<int>& a) {
    int n=a.size();
    int vote = 0;
    int candidate = 0;

    for (int num : a) {
        if (vote == 0) {
            candidate = num;
            vote=1;
        }
        if(num==candidate) 
            vote += 1; 
        else 
            vote -= 1; 
    }
    int count=0;
    for (int i = 0; i < n; i++) {
        if (a[i] == candidate)
            count++;
    }
 
    if (count > n / 2)
        return candidate;
     return -1;
}

    // Time Complexity: O(N) -> O(n+max(Ai))
    // Space Complexity: O(N)
int usingCountSort(vector<int>& a,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxi<a[i])
            maxi=a[i];
    }
    vector<int> count(maxi+1,0);
    int x=n/2;
    for(int i=0;i<n;i++){
        /*if( count[a[i]] > x )
            return a[i];
        else*/
            count[a[i]]++;
    }
    int maxi1=INT_MIN,ans=0;
    for(int i=0;i<=maxi;i++){
        if( count[a[i]] > x ){
            if(maxi1<count[a[i]]){
                maxi1=count[a[i]];
                ans=a[i];
            }
        }
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
    cout<<"Ans(1): "<<usingCountSort(a,n)<<endl;
    cout<<"Ans(2): "<<majorityElement(a)<<endl;



    return 0;
}