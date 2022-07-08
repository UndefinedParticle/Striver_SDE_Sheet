#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
// Space Complexity: O(1)
int maxCount(vector<int> &a){
    int n=a.size();
    int count=0;
    int maxC=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            count++;
            maxC=max(maxC,count);
        }else{
            count=0;
        }
    }

    return maxC;
}

int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout << "The maximum  consecutive 1's are " << maxCount(a)<<endl;


    return 0;
}