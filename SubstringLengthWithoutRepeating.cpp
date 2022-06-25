#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s){
    int n=s.size();
    int length=1;
    int maxi=1;
    for(int i=0;i<n;i++){
        unordered_set<char> st;
        for(int j=i;j<n;j++){
            if(st.find(s[j])!=st.end()){
                length=max(length,j-i);
                break;
            }
            st.insert(s[j]);
        }

    }
    return length;
}


int longestLength(string s){
    int n=s.size();
    unordered_set<char> st;
    int length=1;
    int left=0;
    for(int i=0;i<n;i++){
        if(st.find(s[i])!=st.end()){
            while(left<i && st.find(s[i])!=st.end()){
                st.erase(s[left]);
                left++;
            }
        }
        st.insert(s[i]);
        length=max(length,i-left+1);
    }
    return length;
}

int lengthOfSubstring(string s){
    int n=s.size();
    unordered_map<char,int> mp;
    int left=0,right=0;
    int length=1;
    while(right<n){
        if(mp.find(s[right])!=mp.end())
            left=max(left,mp[s[right]]+1);
        mp[s[right]]=right;
        length=max(length,right-left+1);
        right++;
    }
    return length;
}


int main(){
    cout<<"Enter your String: ";string s;cin>>s;

    cout<<"Length of Longest Substring without any Repeating Character is "<<longestSubstring(s)<<endl;
    cout<<"Length of Longest Substring without any Repeating Character is "<<longestLength(s)<<endl;
    cout<<"Length of Longest Substring without any Repeating Character is "<<lengthOfSubstring(s)<<endl;


    return 0;
}