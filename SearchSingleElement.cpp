#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
int findElement(vector<int> &a){
    int n=a.size();
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1=xor1^a[i];
    }

    return xor1;
}


// Time Complexity: O(log(N))
// Space Complexity: O(1)
int findTheSingleElement(vector<int> &a){
    int n=a.size();
    int low=0;
    int high=n-2;
    while(low<=high){
        int mid=(low+high)>>1;
        if(!(mid&1)){
            if(a[mid] != a[mid+1]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(a[mid] == a[mid+1]){
                high=mid-1;  
            }else{
                low=mid+1;
            }
        }

        /*if(a[mid] == a[mid^1]){
            low=mid+1;
        }else{
            high=mid-1;
        }*/

    }

    return a[low];
}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }
    cout << "The single occurring element is: "<<findElement(a)<<endl;




    return 0;
}