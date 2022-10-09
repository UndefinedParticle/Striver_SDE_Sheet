#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define rloop(i,n,a) for(int i=n;i>=a;i--)

bool isPalindrome(string s){
    
    int left=0,right=s.size()-1;
    while(left<=right){
        if(s[left] != s[right]){
            return false;
        }
        left++,right--;
    }

    return true;
}


//Time Complexity: O(n*n)
int minChar(string s){

    int ans=0;
    int n=s.size();
    string str="";
    string newS="";
    if(isPalindrome(s)) return ans;
    rloop(i,n-1,0){
        str +=s[i];
        newS=str+s;
        ans++;
        if(isPalindrome(newS)){
            return ans;
        }
    }

    return -1;
}

//Time Complexity: O(n)
int minCharsforPalindrome(string s){
    int n=s.size();
    int left=0,right=n-1;
    int cnt=0;
    int rgt=right;
    while(left<=right){
        if(s[left] == s[right]){
            left++,right--;
        }else{
            cnt++;
            left=0;
            rgt--;
            right=rgt;
        }
    }
    return cnt;
      
}

vector<int> createLps(string s){

    int n=s.size();
    vector<int> lps(n);
    int len=0,i=1;

    while(i<n){
        if(s[i] == s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len != 0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int minChar1(string s){
    string str=s;
    reverse(s.begin(),s.end());
    string newS=str+"@"+s;
    vector<int> temp=createLps(newS);


    return s.size()-temp[temp.size()-1];

}




int main(){

    cout<<"Give the string: ";string s;cin>>s;
    cout<<"Min Char For Palindorme: "<<minChar(s)<<endl;
    cout<<"Min Char For Palindorme: "<<minCharsforPalindrome(s)<<endl;






    return 0;
}