#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>>& a,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<i;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<m;i++){
        reverse(a[i].begin(),a[i].end());
    }
}




int main(){

    cout<<"Number of rows: ";
    int m;cin>>m;
    cout<<"Number f columns: ";
    int n;cin>>n;
    cout<<"Array Elements: \n";
    vector<vector<int>> a;
    for(int i=0;i<m;i++){
        vector<int> vt;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            vt.emplace_back(x);
        }
        a.emplace_back(vt);
    }

    vector<vector<int>> rotate;
    for(int i=0;i<n;i++){
        vector<int> vt;
        for(int j=0;j<m;j++){
            int x;
            x=a[m-1-j][i];
            vt.emplace_back(x);
        }
        rotate.emplace_back(vt);
    }
     cout<<"After rotation(method 1): \n";
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             cout<<rotate[i][j]<<" ";
         }cout<<endl;
     }

     cout<<"After rotation(method 2): \n";
     rotateMatrix(a,m,n);
     for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
             cout<<a[i][j]<<" ";
         }cout<<endl;
     }



    return 0;
}