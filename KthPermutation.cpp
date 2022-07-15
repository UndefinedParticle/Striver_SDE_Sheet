#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()


string kthPermutation(string a,int k){
    int n=a.size();

    if(k==1){
        return a;
    }



    loop(p,2,k+1){
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
    return a;
}


// Time Complexity: O(N) * O(N) = O(N^2)
// Reason: We are placing N numbers in N positions. This will take O(N) time.
// For every number, we are reducing the search space by removing the element already placed in the previous step.
// This takes another O(N) time.

// Space Complexity: O(N) 
// Reason: We are storing  the numbers in a data structure(here vector)
string getPermutation(int n,int k){
    int fact=1;
    vector<int> numb;
    loop(i,1,n){
        fact=fact*i;
        numb.emplace_back(i);
    }

    numb.emplace_back(n);
    string ans="";
    k=k-1;
    while(true){
        ans=ans+ to_string(numb[k/fact]);
        numb.erase(numb.begin()+ k/fact);
        if(numb.size()==0)
            break;
        
        k=k%fact;
        fact=fact/numb.size();
    }

    return ans;

}





int main(){

    cout<<"N: ";int n;cin>>n;
    cout<<"K: ";int k;cin>>k;

    string s="abc";
    /*loop(i,1,n+1){
        s.push_back(i+'0');
    }*/

    cout<<s<<endl;


    cout<<"The Kth permutation sequence is " <<getPermutation(n,k)<<endl;






    return 0;
}