#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)



// Time Complexity: O( 2^n *(k log (x) )). 
// 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. 
// After this, we have to convert the set of combinations back into a list of list /vector of vectors which takes more time.

// Space Complexity:  O(2^n * k) to store every subset of average length k. 
// Since we are initially using a set to store the answer another O(2^n *k) is also used.
void printSubset(int ind,vector<int> &a,vector<int> ds,set<vector<int>> &ans,int n){
    
    if(ind==n){
        sort(ds.begin(), ds.end());
        ans.insert(ds);
        return;
    }

    ds.push_back(a[ind]);
    printSubset(ind+1,a,ds,ans,n);

    ds.pop_back();
    printSubset(ind+1,a,ds,ans,n);
    

}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Arrray elements:\n";
    vector<int> a;
    loop(i,0,n){
        int x;cin>>x;
        a.push_back(x);
    }
    cout<<"Subset Sum :\n";
    vector<int> ds;

    set < vector < int >> ans;
    printSubset(0,a,ds,ans,n);
    /*vector<vector<int>> res;

    for (auto it = ans.begin(); it != ans.end(); it++) {
      res.push_back( * it);
    }*/



    for(auto vect:ans){
        for(auto it: vect){
            cout<<it<<" ";
        }cout<<endl;
    }


    return 0;
}