#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()

bool isPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start++] != s[end--])
            return false;
    }
    return true;
}



// Time Complexity: O( (2^n) *k*(n/2) )
// Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
// O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer. 
// k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. 
// The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
void palindromePartition(int ind,string s,vector<string> &ds,vector<vector<string>> &ans,int n){
    if(ind==n){
        ans.push_back(ds);
        return;
    }

    loop(i,ind,n){
        if(isPalindrome(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            palindromePartition(i+1,s,ds,ans,n);
            ds.pop_back();
        }
    }
}



int main(){

    cout<<"String: ";string s;cin>>s;

    vector<vector<string>> ans;
    vector<string> ds;
    palindromePartition(0,s,ds,ans,s.size());

    cout << "The Palindromic partitions are :-" << endl;
    for(auto ita:ans){
        for(auto it:ita){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    




    return 0;
}