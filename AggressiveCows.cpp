#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

bool canPlace(vector<int> &arr,int cow,int dist){
    int n=arr.size();
    int countCows=1;
    int lastCow=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-lastCow >= dist){
            countCows++;
            lastCow=arr[i];
        }
        if(countCows==cow){
            return true;
        }
    }

    return false;


}

// Time Complexity: O(N*log(M)). 
// Reason: For binary search in a space of M, O(log(M))  
// and for each search, we iterate over max N stalls to check. O(N).

// Space Complexity: O(1)
int largestMinDist(vector<int> &arr,int cow){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int low=1,high=arr[n-1]-arr[0];

    while(low<=high){
        int mid=(low+high)>>1;
        if(canPlace(arr,cow,mid)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return high;


}


int main(){

    cout<<"Number of stalls: ";int n;cin>>n;
    cout<<"Array elements:\n";
    vector<int> arr;
    loop(i,0,n){
        int x;cin>>x;
        arr.emplace_back(x);
    }
    cout<<"Number of Cows: ";int cow;cin>>cow;
    
    cout << "The largest minimum distance is " << largestMinDist(arr,cow) << endl;



    return 0;
}

