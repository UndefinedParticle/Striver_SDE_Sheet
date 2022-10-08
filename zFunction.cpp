#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;

vector<int> zFunc(string s){
    int n=s.size();
    vector<int> z(n);
    int l=0,r=0;
    loop(i,1,n){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            l=i;
            r=i+z[i]-1;
        }
    }

    return z;

}

int patternMatch(string s,string p){
    string newS=p + "#" + s;
    int cnt=0;
    int n=newS.size();
    int m=p.size();
    vector<int> z=zFunc(newS);
    loop(i,0,n){
        if(z[i]==m){
            cnt++;
        }
    }
    return cnt;
}


int main(){
    cout<<"Give the string: ";string s;cin>>s;
    int n=s.size();
    //vector<int> z(n);
    vector<int> z=zFunc(s);
    for(auto it:z){
        cout<<it<<" ";
    }cout<<endl;


    return 0;
}