#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(m*n) + O((m*n) log (m*n))
// Space Complexity: O(m*n)
int median1(vector<vector<int>> matrix,int m,int n){
    vector<int> temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    int size=temp.size();
    return temp[size/2];

}


int smallerThanMid(vector<int> &row,int mid){
    int low=0,high=row.size()-1;
    while(low<=high){
        int md=(low+high)>>1;
        if(row[md] <= mid){
            low=md+1;
        }else{
            high=md-1;
        }
    }

    return low;
}


// Time Complexity: O(row*log col)
// Since the upper bound function takes log c time.

// Space Complexity: O(1) since no extra space is required.
int findMedian(vector<vector<int>> &matrix){
    int low=1;
    int high=1e9;
    int m=matrix.size();
    int n=matrix[0].size();
    while(low<=high){
        int mid=(low+high)>>1;
        int count=0;
        for(int i=0;i<m;i++){
            count += smallerThanMid(matrix[i],mid);
        }
        if(count<=((m*n)/2)){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return low;
}


int main(){

    cout<<"Row Size: ";int m;cin>>m;
    cout<<"Column Size: ";int n;cin>>n;
    cout<<"Matrix Elements:\n";
    vector<vector<int>> matrix;
    for(int i=0;i<m;i++){
        vector<int> vt;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            vt.push_back(x);
        }
        matrix.push_back(vt);
    }

    cout<<"Median: "<<median1(matrix,m,n)<<endl;
    cout<<"Median: "<<findMedian(matrix)<<endl;







    return 0;
}