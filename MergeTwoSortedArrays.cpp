#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void merge(vector<int>& a1,vector<int>& a2,int m,int n){
    for(int i=0;i<m;i++){
        if(a1[i]>a2[0])
            swap(a1[i],a2[0]);
        sort(a2.begin(),a2.end());
    }
}


int main(){

    cout<<"Array1 size: ";
    int m;cin>>m;
    cout<<"Array1 elements:\n";
    vector<int> a1;
    for(int i=0;i<m;i++){
        int x;cin>>x;
        a1.emplace_back(x);
    }
    cout<<"Array2 size: ";
    int n;cin>>n;
    cout<<"Array2 elements:\n";
    vector<int> a2;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a2.emplace_back(x);
    }
    vector<int> a3(a1);
    a3.insert(a3.end(),a2.begin(),a2.end());
    sort(a3.begin(),a3.end());
    a1.clear();
    a2.clear();
    a1.insert(a1.begin(),a3.begin(),a3.begin()+m);
    a2.insert(a2.begin(),a3.begin()+m,a3.end());

    cout<<"(1)): \n";
    for(auto it: a1)
        cout<<it<<" ";
    cout<<endl;
    for(auto it: a2)
        cout<<it<<" ";
    cout<<endl;

    cout<<"Ans(2):\n";
    for(auto it: a1)
        cout<<it<<" ";
    cout<<endl;
    for(auto it: a2)
        cout<<it<<" ";
    cout<<endl;

    return 0;
}