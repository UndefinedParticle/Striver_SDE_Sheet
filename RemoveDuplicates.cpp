#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n*log(n))+O(n)+O(n)
// Space Complexity: O(n) 
int removeDuplicates1(vector<int> &a){
    int n=a.size();
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(a[i]);
    }
    int k=st.size();

    int j=0;
    for(auto it:st)
        a[j++]=it;

    a.erase(a.begin()+k,a.end());
    return k;

}

// Time complexity: O(n)
// Space Complexity: O(1)
int removeDuplicates2(vector<int> &a){
    int n=a.size();
    int i=0;
    for(int j=1;j<n;j++){
        if(a[i]!=a[j]){
            i++;
            a[i]=a[j];
        }
    }
    return i+1;
}



int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }

    int k=removeDuplicates1(a);
    for(auto it:a){
        cout<<it<<" ";
    }cout<<endl;


    return 0;
}