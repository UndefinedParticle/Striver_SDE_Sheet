#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> merge(vector<pair<int,int>>& a){
    int n=a.size();
    sort(a.begin(),a.end());
    vector<pair<int,int>> ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || ans.back().second < a[i].first){
            ans.push_back({a[i].first,a[i].second});
        }else{
            ans.back().second=max(ans.back().second,a[i].second);
        }
    }
    return ans;
}

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

    vector<pair<int,int>> ans1=merge(a);
    cout<<"Final ans:\n";
    for(auto it:ans1){
        cout<<it.first<<" "<<it.second<<endl;
    }



    return 0;
}