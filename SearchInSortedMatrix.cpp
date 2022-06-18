#include<bits/stdc++.h>
using namespace std;
//Time complexity: O(log(m*n))
// Space complexity: O(1)
int binarySearch(vector<vector<int>>& a,int target){  
    int low=0;
    int high=(a.size() * a[0].size())-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(a[mid/a[0].size()][mid % a[0].size()] == target) {
                return 1;
            }
            if(a[mid/a[0].size()][mid % a[0].size()] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
    }
    return 0;
}


int main(){
    cout<<"Row size: ";
    int m;cin>>m;
    cout<<"Column size: ";
    int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<vector<int>> a;
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            v.emplace_back(x);
        }
        a.emplace_back(v);
    }
    cout<<"Target element: ";
    int x;cin>>x;
    cout<<"Ans(1): ";// Time complexity: O(m*n)
    bool ans1=false;;// Space complexity: O(1)
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(x==a[i][j]){
                ans1=true;
                break;
            }
        }
    }cout<<ans1<<endl;

    cout<<"Ans(2): "<<binarySearch(a,x)<<endl;

    return 0;
}