#include<bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<stack>
// #include<climits>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define rloop(i,n,a) for(int i=n;i>=a;i--)




// Time Complexity: O(N*N ) 
// Space Complexity: O(1)
int largestarea(vector<int> &a, int n) {
    int maxi=0;
    loop(i,0,n){
        int mini=INT_MAX;
        loop(j,i,n){
            mini=min(mini,a[j]);
            maxi=max(maxi,mini*(j-i+1));
            //cout<<mini<<" "<<maxi<<endl;
        }
    }
  
  return maxi;
}



// Time Complexity: O( N )

// Space Complexity: O(3N) where 3 is for the stack, 
// left small array and a right small array
int areaOfRectangle(vector<int> &a,int n){
    int area=1;
    stack<int> st;
    vector<int> ans1(n,0);

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()] >= a[i]){
            st.pop();
        }
        if(i<n){
            if( !st.empty()){
                ans1[i]=st.top()-1;
            }else{
                ans1[i]=n-1;
            }
        }
        st.push(i);
    }


    stack<int> st1;
    vector<int> ans2(n,0);
    for(int i=0;i<n;i++){
        while(!st1.empty() && a[st1.top()] >= a[i]){
            st1.pop();
        }
        if(i<n){
            if( !st1.empty()){
                ans2[i]=st1.top()+1;
            }else{
                ans2[i]=0;
            }
        }
        st1.push(i);
    }

    int maxi=-1;

    loop(i,0,n){
        int temp=a[i]* (ans1[i]-ans2[i]+1);
        if(temp > maxi){
            maxi=temp;
        }
    }

    return maxi;

}


// Time Complexity: O( N ) + O (N)
// Space Complexity: O(N)
int rectangleArea(vector<int> &a,int n){

    stack<int> st;
    int maxArea=0;
    loop(i,0,n+1){
        while(!st.empty() && (i==n || a[st.top()] >= a[i])){
            int height=a[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width=1;
            }else{
                width = i - st.top() - 1;
            }
            maxArea=max(maxArea,width*height);
        }
        st.push(i);
    }

    return maxArea;

}




int main(){

    cout<<"Array Size: ";int n;cin>>n;
    cout<<"Array Elements:\n";
    vector<int> a(n);
    loop(i,0,n){
        cin>>a[i];
    }

    cout<<"Area: "<<areaOfRectangle(a,n)<<endl;
    cout<<"Area: "<<largestarea(a,n)<<endl;
    cout<<"Area: "<<rectangleArea(a,n)<<endl;


    return 0;
}