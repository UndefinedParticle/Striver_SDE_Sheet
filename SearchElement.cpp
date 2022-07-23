#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> &a,int target){
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==target){
            return i+1;
        }
    }

    return -1;
}


// Time Complexity: O(log(N))
// Reason: We are performing a binary search,
// this turns time complexity to O(log(N)) where N is the size of the array.

// Space Complexity: O(1)
// Reason: We do not use any extra data structure, 
// this turns space complexity to O(1).
int binarySearch(vector<int> &a,int target){
    int n=a.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(a[mid]==target){
            return mid+1;
        }
        if(a[low]<=a[mid]){
            if(a[low]<=target && target<=a[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(a[mid]<=target && target<=a[high]){
                low=mid+1;   
            }else{
                high=mid-1;
            }
        }
    }


    return -1;


}



int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout<<"Target value: ";int target;cin>>target;

    cout << "The single occurring element is: "<<linearSearch(a,target)<<endl;
    cout << "The single occurring element is: "<<binarySearch(a,target)<<endl;




    return 0;
}