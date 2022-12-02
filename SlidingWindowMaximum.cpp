#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

// Time Complexity: O(n^2)
// Space Complexity: O(k)
vector<int> slidingWindow(vector<int> &a,int n,int k){
    int maxi=-999;
    vector<int> ans;
    loop(i,0,k){
        if(maxi<a[i]){
            maxi=a[i];
        }
    }ans.push_back(maxi);
    int left=1,right=k;

    while(right<n){
        maxi=-999;
        loop(i,left,right+1){
            if(maxi<a[i]){
                maxi=a[i];
            }
        }
        left++;
        right++;
        ans.push_back(maxi);
    }

    return ans;

}

// Time Complexity: O(n)
// Space Complexity: O(k)
vector<int> maxSlidingWindow(vector<int> &a,int n,int k){

    deque<int> dq;
    vector<int> ans;

    loop(i,0,n){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }

        while(!dq.empty() && a[dq.back()] <= a[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        if(i >= k-1){
            ans.push_back(a[dq.front()]);
        }
    }


    return ans;
}





int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a(n);
    loop(i,0,n){
        cin>>a[i];
    }
    cout<<"Value of K: ";int k;cin>>k;

    vector<int> ans=slidingWindow(a,n,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;




    return 0;
}