#include<bits/stdc++.h>
using namespace std;

void setColors(vector<int>& a,int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        switch(a[mid]){
            case 0:
                swap(a[mid],a[low]);
                mid++,low++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid],a[high]);
                high--;

        }
    }
}


int main(){

    cout<<"Array Size: ";
    int n;cin>>n;
    cout<<"Enter the elements of the array: ";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    
    }
    cout<<"Final Ans: \n";
    setColors(a,n);
    for(auto it: a){
        cout<<it<<" ";
    }cout<<endl;



    return 0;
}