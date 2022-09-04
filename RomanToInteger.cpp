#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

int romanToInt(char ch){
    switch(ch){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
    }
    return 0;
}



int main(){

    cout<<"String input: ";string s;cin>>s;
    int sum=0;
    int n=s.size();
    loop(i,0,n){

        if(s[i]=='I' && s[i+1]=='V' && i<n) {
            sum+=4;
            i++;
        }
        else if(s[i]=='I' && s[i+1]=='X' && i<n){
            i++;
            sum+=9;
        }
        else if(s[i]=='X' && s[i+1]=='L' && i<n) {
            sum+=40;
            i++;
        }
        else if(s[i]=='X' && s[i+1]=='C' && i<n) {
            sum+=90;
            i++;
        }
        else if(s[i]=='C' && s[i+1]=='D' && i<n) {
            sum+=400;
            i++;
        }
        else if(s[i]=='C' && s[i+1]=='M' && i<n) {
            sum+=900;
            i++;
        }
        else sum+=romanToInt(s[i]);
    }
 
    cout<<"Roman to Int: "<<sum<<endl;



    return 0;
}