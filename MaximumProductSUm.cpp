#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProduct(vector<int> &a,int n){
    int p=1;
    int maxi=INT_MIN;        
    for(int i=0;i<n;i++){        
        p*=a[i];        
        maxi=max(maxi,p);                
        if(p==0){            
            p=1;        
        }    
    }    
    p=1;        
    for(int i=n-1;i>=0;i--){        
        p*=a[i];        
        maxi=max(maxi,p);                
        if(p==0){            
            p=1;        
        }    
    }        
    return maxi;
}


// Time Complexity: O(n)
// Space Complexity: O(1)
int kadanesAlgo(vector<int> &a,int n){

    int prod1 = a[0],prod2 = a[0],maxP = a[0];
    
    loop(i,1,n){
        int temp = max({a[i],prod1*a[i],prod2*a[i]});
        prod2 = min({a[i],prod1*a[i],prod2*a[i]});
        prod1 = temp;
        
        maxP = max(maxP,prod1);
    }
    
    return maxP;
}


int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a(n);
    loop(i,0,n){
        cin>>a[i];
    }

    cout<<"Max Product: "<<maxProduct(a,n)<<endl;
    cout<<"Max Product: "<<kadanesAlgo(a,n)<<endl;

    return 0;
}