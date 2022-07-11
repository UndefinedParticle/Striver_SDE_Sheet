#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

int minimumCoin(int v){
    int a[]={ 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n=sizeof(a)/sizeof(a[0]);

    int count=0;
    
    
    for(int i=n-1;i>=0;i--){
        while(a[i]<=v){

            v=v-a[i];
            count++;

        }

    }

    return count;

}


int main(){

    
    cout<<"Enter the value: ";int v;cin>>v;
    cout<<"The minimum number of coins is "<<minimumCoin(v)<<endl;





    return 0;
}