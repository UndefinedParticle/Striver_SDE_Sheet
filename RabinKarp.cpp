#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,a,n) for(ll i=a;i<n;i++)
//#define ll long long
const int p=31;
//const int N=1e5+7;
const int m=1e9+7;


ll rabinKarp(string source,string target){

    if(source=="" || target=="") 
        return -1;
    int n=target.size();
    int s=source.size();
    ll x=max(n,s)+2;
    vector<ll> pw(x+2);
    pw[0]=1;
    loop(i,1,x+1){
        pw[i]=(pw[i-1]*p)%m;
    }
    
    ll targetCode=0;
    //ll power=1;
    loop(i,0,n){
        targetCode =(targetCode + (target[i]-'0'+1)*pw[i])%m;
    }

    vector<ll> sourceCode(s+2,0);
    //ll sourceCode=0;
    //power=1;
    loop(i,0,source.size()){
        sourceCode[i+1] =(sourceCode[i] + (source[i]-'0'+1)*pw[i])%m;
    }

    for(int i=0;i+n-1<s;i++){
        ll curHash=(sourceCode[i+n] - sourceCode[i])%m;
        if(curHash<0)
            curHash+=m;
        if(curHash == (targetCode*pw[i])%m){
            //if(source.substr(i-n+1) == target){
                return i;
            //}
        }
    }

    return -1;

}


ll matchString(string a,string b){
    if(a==b) 
        return 1;
    int cnt=1;
    string source=a;
    while(source.size()<b.size()){
        cnt++;
        source+=a;
    }

    if(source==b) 
        return cnt;
    if(rabinKarp(source,b) != -1)
        return cnt;
    if(rabinKarp(source+a,b) != -1)
        return cnt+1;

    
    return -1;
}



int main(){

    cout<<"First String: ";string a;cin>>a;
    cout<<"Second String: ";string b;cin>>b;

    cout<<"Minimum number of times I should repeat string: "<<matchString(a,b)<<endl;
        



    return 0;
}