#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Time Complexity : O(n^3); 3 loops
// Space Complexity : O(3*k); k is the no.of triplets
vector<vector<int>> threeSum(vector<int> &a){
    int n=a.size();
    vector<vector<int>> ans;
    vector<int> vt;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                vt.clear();
                if(a[i]+a[j]+a[k] == 0){
                    vt.emplace_back(a[i]);
                    vt.emplace_back(a[j]);
                    vt.emplace_back(a[k]);
                }
                if(vt.size() != 0)
                    ans.push_back(vt);
            }
        }
    }
    return ans;
}

// Time Complexity : O(n^2)  
// Space Complexity : O(3*k); k is the no.of triplets
vector<vector<int>> threeSum1(vector<int> &a){

    int n=a.size();
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i==0 || (i>0 && a[i]!=a[i-1])){
            int low=i+1,high=n-1,sum=0-a[i];
            while(low<high){
                if(a[low]+a[high] == sum){
                    vector<int> vt;
                    vt.emplace_back(a[i]);
                    vt.emplace_back(a[low]);
                    vt.emplace_back(a[high]);

                    ans.push_back(vt);


                    while(low<high && a[low]==a[low+1])
                        low++;
                    while(low<high && a[high]==a[high-1])
                        high--;
                    low++;
                    high--;


                }else if(a[low]+a[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }

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
    vector<vector<int>> ans1=threeSum(a);
    for(auto vec:ans1){
        for(auto it:vec)
            cout<<it<<" ";
        cout<<endl;
    }

    cout<<"Ans(2):\n";
    vector<vector<int>> ans2=threeSum(a);
    for(auto vec:ans2){
        for(auto it:vec)
            cout<<it<<" ";
        cout<<endl;
    }



    return 0;
}