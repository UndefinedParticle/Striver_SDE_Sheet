#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define ll long long
const int p=31;
const int m=1e9+7;


ll calculateHash(string &s){
    ll myHash=0;
    ll power=1;

    loop(i,0,s.size()){
        myHash =(myHash + (s[i]-'0'+1)*power)%m;
        power=(power*p)%m;
    }

    return myHash;
}

int rabinKarp(string source,string target){

    if(source=="" || target=="") return -1;
    int n=target.size();
    



}


int matchString(string a,string b){
    if(a==b) return 1;
    int cnt=1;
    string source=a;
    while(a.size()<b.size()){
        cnt++;
        source+=a;
    }

    if(source==b) return cnt;
    //if()


}



int main(){

    cout<<"First String: ";string a;cin>>a;
    cout<<"Second String: ";string b;cin>>b;
        



    return 0;
}