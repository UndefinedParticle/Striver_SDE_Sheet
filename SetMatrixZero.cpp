#include<bits/stdc++.h>
using namespace std;


int main(){
    cout<<"no. of row: ";
    int m;cin>>m;
    cout<<"no. of column: ";
    int n;cin>>n;
    cout<<"give the elements of the array: \n";
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    vector < int > a1(m,-1);
    vector<int> a2(n,-1);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                a1[i]=0;
                a2[j]=0;
            }
                
        }
    }

    cout<<"Ans: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a1[i]==0 || a2[j]==0){
                cout<<"0 ";
            }else{
                cout<<a[i][j]<<" ";
            }
        }cout<<endl;
    }
   





    return 0;
}