#include<bits/stdc++.h>
using namespace std;


int findElement(vector<int> &a){
    int n=a.size();
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^a[i];
    }

    return xor1;
}


int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout << "The single occurring element is: "<<findElement(a)<<endl;




    return 0;
}