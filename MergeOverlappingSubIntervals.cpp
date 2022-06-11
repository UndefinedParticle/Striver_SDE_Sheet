#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> mergeIntervals(vector<pair<int,int>>& a){
    int n=a.size();
    sort(a.begin(),a.end());
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        int start=a[i].first,end=a[i].second;
        if(!ans.empty()){
            if(start<=ans.back().second)
                continue;
        }

        for(int j=i+1;j<n;j++){
            if(a[j].first<end){
                end=a[j].second;
            }
        }

        ans.push_back({start,end});
    }
    return ans;
}


int main(){

    cout<<"number of intervals: ";
    int n;cin>>n;
    cout<<"Intervals: \n";
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        a.emplace_back(make_pair(x,y));
    }
    vector<pair<int,int>> ans=mergeIntervals(a);
    cout<<"Final ans:\n";
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }



    return 0;
}