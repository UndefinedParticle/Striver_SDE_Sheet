#include<bits/stdc++.h>
using namespace std;

// n is the length of the string
// Time Complexity: O( (2^n) *k*(n) )
// Reason: O(2^n) to generate every substring and O(n) to check if the substring generated is present in the dictionary or not.
// O(k) is for inserting the words in another data structure, where k is the average length of the word list.

// Space Complexity: O(k * x)
// Reason: The space complexity can vary depending upon the length of the answer.
// k is the average length of the list of wors and if we have x such list of words in our final answer.
// The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
void getSentence(int ind,string s,vector<string> &dictionary,vector<string> word,vector<vector<string>> &ans){
    if(ind==s.size()){
        ans.push_back(word);
        return;
    }

    for(int i=ind;i<s.size();i++){
        //t.c. of find-> O(n)
        if(find(dictionary.begin(),dictionary.end(),s.substr(ind,i-ind+1)) != dictionary.end()){
            word.push_back(s.substr(ind,i-ind+1));
            getSentence(i+1,s,dictionary,word,ans);
            word.pop_back();    
        }
    }
}



int main(){

    cout<<"Size of the dictionary: ";int n;cin>>n;
    vector<string> dictionary;
    cout<<"Wordlist: \n";
    for(int i=0;i<n;i++){
        string s;cin>>s;
        dictionary.push_back(s);
    }
    cout<<"Give the string: ";string s;cin>>s;

    vector<vector<string>> ans;
    vector<string> word;
    getSentence(0,s,dictionary,word,ans);
    cout<<"All sentences are: \n";
    for(auto vect:ans){
        for(auto it:vect){
            cout<<it<<" ";
        }cout<<endl;
    }
    





    return 0;
}