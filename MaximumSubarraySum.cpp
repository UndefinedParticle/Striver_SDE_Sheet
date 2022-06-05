#include<bits/stdc++.h>
using namespace std;


int main(){

    cout<<"Array size: ";
    int n;cin>>n;
    cout<<"Array Elements: ";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    
    int max=0;
    int i1,j1;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+a[j];
            if(sum>max){
                max=sum;
                i1=i;
                j1=j;
            }
        }
    }

    cout<<"Subaray is : \n";
    for(int k=i1;k<=j1;k++){
        cout<<a[k]<<" ";
    }cout<<endl;


    cout<<"Maximum sum is: "<<max<<endl;




    return 0;
}