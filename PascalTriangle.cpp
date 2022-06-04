#include<bits/stdc++.h>
using namespace std;


int main(){
    cout<<"Enter an integer: ";
    int n;cin>>n;
    vector<vector<int>> vt(n);
    for(int i=0;i<n;i++){
        vt[i].resize(i+1);
        vt[i][0]=vt[i][i]=1;
        for(int j=1;j<i;j++){
            vt[i][j]=vt[i-1][j-1] + vt[i-1][j];
            
        }
    }
    for(int i=0;i<n;i++){
        for(int k=1;k<=n-i-1;k++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
            cout<<vt[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}