#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> FourSum(vector<int>& a,int x){
    vector<vector<int>> ans;
    int n=a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int value3=x-a[i];
        for(int j=i+1;j<n;j++){
            int value2=value3-a[j];
            int left=j+1;
            int right=n-1;
            while(left<right){
                int twoSum=a[left]+a[right];
                if(twoSum<value2)
                    left++;
                else if(twoSum>value2)
                    right--;
                else{
                    vector<int> temp(4,0);
                    temp[0]=a[i];
                    temp[1]=a[j];
                    temp[2]=a[left];
                    temp[3]=a[right];

                    ans.emplace_back(temp);
                    
                    while(left<right && a[left]==temp[2])
                        left++;
                    while(left<right && a[right]==temp[3])
                        right--;
                    
                }
            }
            while(j+1<n && a[j+1]==a[j])
                j++;
        }
        while(i+1<n && a[i+1]==a[i])
            i++;
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
    cout<<"Target element: ";int x;cin>>x;
    vector<vector<int>> ans=FourSum(a,x);
    for(auto vect:ans){
        for(auto it: vect){
            cout<<it<<" ";
        }
        cout<<endl;
    }



    return 0;
}