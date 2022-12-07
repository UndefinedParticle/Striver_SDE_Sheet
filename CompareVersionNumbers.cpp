#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
typedef long long ll;


int compareVersions(string a, string b) 
{
    ll num1=0,num2=0;
    ll i=0,j=0;
    while(i<a.length() || j<b.length()){
        while(i<a.length() && a[i]!='.'){
            num1=num1*10 + (a[i]-'0');
            i++;
        }
        while(j<b.length() && b[j]!='.'){
            num2=num2*10 + (b[j]-'0');
            j++;
        }

        if(num1 > num2) return 1;
        if(num1 < num2) return -1;
        num1=0,num2=0;
        i++;
        j++;
    }

    return 0;
}


int main(){

    cout<<"String A: ";string a;cin>>a;
    cout<<"String B: ";string b;cin>>b;







    return 0;
}