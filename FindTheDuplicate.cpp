#include<bits/stdc++.h>
using namespace std;
int findDuplicate1(vector<int>& a){
    int n=a.size();
    int freq[n+1]={0};
    for(int i=0;i<n;i++){
        if(freq[a[i]]==0){
            freq[a[i]]++;
        }else
            return a[i];
    }
    return 0;
}

 int findDuplicate2(vector<int>& a){
     int n=a.size();
     int slow=a[0];
     int fast=a[0];
     do{
        slow=a[slow];
        fast=a[a[fast]];

     }while (slow!=fast);
     fast=a[0];
     while (slow!=fast){
        slow=a[slow];
        fast=a[fast];
     }
     return slow;
       
 }

int main(){

    cout<<"Array size: ";
    int n;cin>>n;
    cout<<"Array elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    sort(a.begin(),a.end());//O(nlog(n))
    cout<<"Ans(1): \n";
    for(int i=0;i<n;i++){  //O(n)
        if(a[i]==a[i+1]){
            cout<<a[i]<<endl;
            break;
        }
    }
    cout<<"Ans(2): "<<findDuplicate1(a)<<endl;
    cout<<"Ans(3): "<<findDuplicate2(a)<<endl;

    return 0;
}