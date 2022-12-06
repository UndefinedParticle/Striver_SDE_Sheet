#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

// Time Complexity: O(n^3)
// Space Complexity: O(1)
vector<int> maxMinWindow1(vector<int> &a,int n){
    vector<int> ans;

    loop(k,1,n+1){
        int maxi=INT_MIN;
        for(int i=0;i<=n-k;i++){
            int mini=INT_MAX;
            loop(j,0,k){
                mini=min(mini,a[i+j]);
            }
            maxi=max(maxi,mini);
        }
        ans.push_back(maxi);
    }

    return ans;
}





vector<int> nextSmaller(vector<int> &a,int n){
    stack<int> st;
    vector<int> ans1(n,0);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
    
        if( !st.empty()){
            ans1[i]=st.top();
        }else{
            ans1[i]=n;
        }
        
        st.push(i);
    }
    return ans1;
}

vector<int> prevSmaller(vector<int> &a,int n){
 stack<int> st1;
    vector<int> ans2(n,0);
    for(int i=0;i<n;i++){
        while(!st1.empty() && a[st1.top()] >= a[i]){
            st1.pop();
        }
        if( !st1.empty()){
            ans2[i]=st1.top();
        }else{
            ans2[i]=-1;
        }
        st1.push(i);
    }
    return ans2;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
vector<int> maxMinWindow(vector<int> a,int n){
    vector<int> nextS=nextSmaller(a,n);
    vector<int> prevS=prevSmaller(a,n);

    vector<int> ans(n,INT_MIN);
    loop(i,0,n){
        int j=(nextS[i]-prevS[i]-1)-1;
        ans[j]=max(ans[j],a[i]);
    }

    for(int i=n-2;i>=0;i--){
        ans[i]=max(ans[i],ans[i+1]);
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
    cout<<"Ans:\n";
    vector<int> ans1=maxMinWindow1(a,n);
    for(auto it:ans1){
        cout<<it<<" ";
    }cout<<endl;


    vector<int> ans=maxMinWindow(a,n);
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;


    return 0;
}