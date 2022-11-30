#include<iostream>
#include<stack>
#include<vector>
#include<iterator>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

vector<int> nextGreater(int a[],int n){

    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() >= a[i]){
            st.pop();
        }
        if(i<n){
            if( !st.empty()){
                ans[i]=st.top();
            }
        }
        st.push(a[i]);
    }
    return ans;
}


int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements: \n";
    int a[n];
    loop(i,0,n){
        cin>>a[i];
    }
    vector<int> ans=nextGreater(a,n);

    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;



    return 0;
}