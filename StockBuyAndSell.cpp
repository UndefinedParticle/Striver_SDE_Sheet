#include<bits/stdc++.h>
using namespace std;

int kadanesAlgo(vector<int>& a,int n){

    int maxProfit=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++){
        minPrice=min(minPrice,a[i]);
        maxProfit=max(maxProfit,a[i]-minPrice);
    }

    return maxProfit;
}


int main(){

    cout<<"Number of days: ";
    int n;cin>>n;
    cout<<"Enter the prices: ";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }

    int max=0;
    for(int i=0;i<n;i++){
        int profit=0;
        for(int j=i;j<n;j++){
            profit=a[j]-a[i];
            if(profit>max){
                max=profit;
            }
        }
    }
    cout<<"MAx profit is: "<<max<<endl;
    cout<<"MAx profit is: "<<kadanesAlgo(a,n)<<endl;



    return 0;
}