#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


int main(){
    cout<<"Number of strings: ";int n;cin>>n;
    cout<<"Give the Strings: ";
    vector<string> s;
    loop(i,0,n){
        string x;cin>>x;
        s.push_back(x);
    }
    sort(s.begin(),s.end());
    string ans="";

    loop(i,0,s[0].size()){
        if(s[0][i]==s[n-1][i]){
            ans+=s[0][i];
        }else{
            break;
        }
    }

    cout<<"Longest Common Prefix is: "<<ans<<endl;



    return 0;
}