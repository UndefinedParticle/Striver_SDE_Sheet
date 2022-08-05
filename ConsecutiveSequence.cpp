#include<bits/stdc++.h>
using namespace std;

int longestSequence(vector<int>& a,int n){
    if(a.empty())
        return 0;
    sort(a.begin(),a.end());
    int count=1,maxi=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]+1){
            count++;
        }else if(a[i]==a[i-1])
            continue;
        else
            count=1;
        maxi=max(maxi,count);
    }
    return maxi;
}

int LongestLength(vector<int> &a){
    set<int> st;
    for(int num:a){
        st.insert(num);
    }
    int length=0;
    for(int num:a){
        if(!st.count(num-1)){
            int curNum=num;
            int curLength=1;
            while(st.count(curNum+1)){
                curNum +=1;
                curLength +=1;
            }
            length=max(length,curLength);
        }
    }
    return length;
}



int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }

    cout<<"Ans(1): "<<longestSequence(a,n)<<endl;
    cout<<"Ans(2): "<<LongestLength(a)<<endl;



    return 0;
}