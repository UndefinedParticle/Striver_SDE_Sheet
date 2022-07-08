#include<iostream>
#include<vector>
using namespace std;

// Time Complexity: O(n*n)
// Space Complexity: O(1)
int waterTrap1(vector<int> &a){
    int n=a.size();
    int sum=0;
    
    for(int i=0;i<n;i++){
        int j=i;
        int leftMax=0,rightMax=0;
        while(j>=0){
            leftMax=max(leftMax,a[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMax=max(rightMax,a[j]);
            j++;
        }

        sum += min(leftMax,rightMax)-a[i];
    }
    return sum;
}


// Time Complexity: O(n)
// Space Complexity: O(n)+O(n)
int waterTrap2(vector<int> &a){
    int n=a.size();
    
    int preMax[n];
    preMax[0]=a[0];
    for(int i=1;i<n;i++){
        preMax[i]=max(preMax[i-1],a[i]);
    }

    int postMax[n];
    postMax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        postMax[i]=max(postMax[i+1],a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum += min(preMax[i],postMax[i])-a[i];
    }


    return sum;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
int waterTrap3(vector<int> &a){

    int n=a.size();
    int sum=0;
    int left=0,right=n-1;
    int leftMax=0,rightMax=0;
    while(left<=right){
        if(a[left]<=a[right]){
            if(a[left]>=leftMax)
                leftMax=a[left];
            else
                sum += leftMax-a[left];
            left++;
        }else{
            if(a[right]>=rightMax)
                rightMax=a[right];
            else
                sum +=rightMax-a[right];
            right--;
        }
    }

    return sum;

}



int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.emplace_back(x);
    }

    cout << "The water that can be trapped is " << waterTrap1(a) << endl;
    cout << "The water that can be trapped is " << waterTrap2(a) << endl;
    cout << "The water that can be trapped is " << waterTrap3(a) << endl;




    return 0;
}