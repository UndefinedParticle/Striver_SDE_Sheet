#include<bits/stdc++.h>
using namespace std;
set<int> usingCountSort(vector<int>& a,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(maxi<a[i])
            maxi=a[i];
    }
    vector<int> count(maxi+1,0);
    int x=n/3;
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    set<int> st;
    for(int i=0;i<=maxi;i++){
        if( count[a[i]] > x ){
            st.insert(a[i]);
            
        }
    }
    return st;
}

vector < int > majorityElement(vector<int>& arr, int n) {
  unordered_map < int, int > mp;
  vector < int > ans;

  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  for (auto x: mp) {
    if (x.second > (n / 3))
      ans.push_back(x.first);
  }

  return ans;
}

vector < int > VotingAlgo(vector<int>& nums, int n) {
  int sz = n;
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}

int main(){
    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout<<"Ans(1):\n";
    set<int> ans=usingCountSort(a,n);
    for(auto it:ans){
        cout<<it<<" ";
    }cout<<endl;


    return 0;
}