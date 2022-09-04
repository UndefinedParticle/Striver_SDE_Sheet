#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define ll long long int

/*

int myAtoi(string s) {
        
        long ans=0;
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ')i++;
        int sign = 1;
        if(i<n)
        {
            if(s[i]=='-')sign=-1,i++;
            else if(s[i]=='+')i++;
            
            while(i<n && isdigit(s[i]))
            {
                ans = ans*10 + (s[i]-'0');
                i++;
                if(ans > INT_MAX && sign == -1)return INT_MIN;
                if(ans > INT_MAX && sign ==1)return INT_MAX;
            }
        }
        ans*=sign;
        return ans;

*/


int main(){
    cout<<"Give the String: ";
    string s;getline(cin,s);
    ll n=s.size();
    ll ans=0;
    ll sign=1;
    bool flag=false;
    bool flag1=false;
    bool flag2=false;
    loop(i,0,n){
        
        if(s[i]==' ' && flag==false){
           continue;
            
        }
        if(s[i]=='+'  && flag==false && flag1==false){
            sign=1;
            flag1=true;
            flag=true;
        }else if((s[i]=='-') && flag==false && flag1==false){
            sign=-1;
            flag1=true;
            flag=true;
        }else if(48<=s[i] && s[i]<=57){
            ans=ans*10 + (s[i]-'0');
            flag=true;
            /*if(ans > INT_MAX && sign == -1)
                return INT_MIN;
            if(ans > INT_MAX && sign ==1)
                return INT_MAX;*/
        }else{
            break;
        }
        


    }

    if(ans>INT_MAX && sign<0)
        ans=INT_MIN;
    else if(ans>INT_MAX && sign>0)
        ans=INT_MAX;
    else
        ans=sign*ans;
    


    cout<<"Integer Value is: "<<ans<<endl;



    return 0;
}