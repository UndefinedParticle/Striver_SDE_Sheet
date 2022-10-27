#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

vector<int> lps(string s){
    int n=s.size();
    vector<int> ans(n,0);

    loop(i,1,n){
        int j=ans[i-1];
        while(j>0 && s[i]!=s[j]){
            j=ans[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        ans[i]=j;
    }


    return ans;
}




int main(){

    cout<<"String: ";string s;cin>>s;


    vector<int> ans=lps(s);
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;



    return 0;
}