#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

bool isPalindrome1(string s){
    int n=s.size();
    int low=0,high=n-1;
    while(low<=high){
        if(s[low] != s[high]){
            return false;
        }
        low++,high--;
    }

    return true;

}




string longestPalindrome1(string s){
    
    int n=s.size();
    string ans="";
    int lnth=0;
    loop(i,0,n){
        loop(j,i,n){
            if(isPalindrome1(s.substr(i,j-i+1)) && (j-i+1)>lnth){
                lnth=(j-i+1);
                ans=s.substr(i,j-i+1);
            }
        }
    }

    return ans;

}

string isPalindrome2(string s,int left,int right){
    int n=s.size();
    while(left>=0 && right<n){
        if(s[left] != s[right]){
            break;
        }
        left--,right++;
    }

    return s.substr(left+1,right-left-1);

}

string longestPalindrome2(string s){
    
    int n=s.size();
    if(s.empty()){
        return "";
    }
    string ans="";
    //int lnth=0;
    loop(i,0,n){
        string ans1=isPalindrome2(s,i,i);
        if(ans1.length()>ans.length()){
            ans=ans1;
        }
    }

    loop(i,0,n){
        string ans2=isPalindrome2(s,i,i+1);
        if(ans2.length()>ans.length()){
            ans=ans2;
        }
    }

    return ans;

}



int main(){

    cout<<"Give the String: ";
    string s;cin>>s;

    cout<<"Longest Palindromic Substring: \n";
    cout<<longestPalindrome1(s)<<endl;
    cout<<longestPalindrome2(s)<<endl;




    return 0;
}