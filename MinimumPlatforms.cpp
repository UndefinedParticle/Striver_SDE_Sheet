#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(nlogn) Sorting takes O(nlogn) and 
//                 traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)  (No extra space used).
int minPlatforms(int a[],int d[],int n){
   sort(a,a+n);
   sort(d,d+n);
   int ans=1,count=1;
   int i=1,j=0;
   while(i<n && j<n){
    if(a[i]<=d[j]){
        count++;
        i++;
    }else{
        count--;
        j++;
    }
    ans=max(ans,count);
   }

   return ans;
}



int main(){

    cout<<"Number of platforms: ";int n;cin>>n;
    cout<<"Arriviing time: \n";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Deparature time:\n";
    int d[n];
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    cout<<"Minimum number of Platforms required "<<minPlatforms(a,d,n)<<endl;




    return 0;
}