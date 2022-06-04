#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& a,int n){

    int i,j;
    for(i=n-2;i>=0;i--){
        if(a[i]<a[i+1])
            break;
    }

    if(i<0)
        reverse(a.begin(),a.end());
    
    else{
        for(j=n-1;j>i;j--){
            if(a[j]>a[i]){
                break;
            }
        }
        swap(a[i],a[j]);
        reverse(a.begin()+i+1,a.end());
    }
    


}


int main(){
    cout<<"Size of the array: ";
    int n;cin>>n;
    cout<<"Array elements: ";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    
    cout<<"Next permutation is: \n";
    nextPermutation(a,n);
    for(auto it:a){
        cout<<it<<" ";
    }cout<<endl;
    



    return 0;
}