#include<bits/stdc++.h>
using namespace std;

double multiply(double numb,int n){
    double ans=1.0;
    for(int i=1;i<=n;i++){
        ans *= numb;
    }

    return ans;
}


// Time Complexity: N x log(M x 10^d) , where  is the d-th decimal places
// Space Complexity: O(1)
double getNthRoot(int m,int n){
    double low=1,high=m;
    double eps=1e-6;//10^(-6)
    while((high-low)>eps){
        double mid=(low+high)/2.0;
        if(multiply(mid,n)<m){
            low=mid;
        }else{
            high=mid;
        }
    }

    return low;
}

/*

long double power(long double mid, int n){
    long double ans = 1.0;
    while(n--)
        ans *= mid;
    return ans;
}

long double findNthRootOfM(int n, long long m) {
    long double low = 1.0, high = (long double)m, eps = 1e-9;
    while((high-low)>eps){
        long double mid = (high-low)/2.0 + low;
        if(power(mid,n)>(long double)m)
            high = mid;
        else
            low = mid;
    }
    return low;
}

*/



int main(){

    cout<<"M: ";int m;cin>>m;
    cout<<"N: ";int n;cin>>n;

    cout<<"N-th Root of M is: "<<getNthRoot(m,n)<<endl;





    return 0;
}