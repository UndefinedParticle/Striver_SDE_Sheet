#include<bits/stdc++.h>
using namespace std;

int countPath(int i,int j,int m,int n){
    if(i==(m-1) && j==(n-1)) return 1;
    if(i>=m || j>=n)
        return 0;
    else
        return countPath(i+1,j,m,n)+countPath(i,j+1,m,n);
    
}

// Time Complexity: The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
// Space Complexity: As we are using extra space for the dummy matrix the space complexity will also be O(n*m).
int countPathByDp(int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i==(m-1) && j==(n-1)) return 1;
    if(i>=m || j>=n)
        return 0;
    if(dp[i][j]!=-1) 
        return dp[i][j];
    else
        return countPathByDp(i+1,j,m,n,dp)+countPathByDp(i,j+1,m,n,dp);
    
}

// Time Complexity: The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.
// Space Complexity: As we are not using any extra space the space complexity of the solution will be  O(1).
int uniquePathByCombination(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }

int main(){

    cout<<"Row: ";int m;cin>>m;
    cout<<"Column: ";int n;cin>>n;
    int totalCount=countPath(0,0,m,n);
    //Ans(1)
    cout<<"The total number of Unique Paths are "<<totalCount<<endl;
    //Ans(2)
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int totalCount1=countPathByDp(0,0,m,n,dp);
    cout<<"The total number of Unique Paths are "<<totalCount1<<endl;
    //Ans(3)
    cout<<"The total number of Unique Paths are "<<uniquePathByCombination(m,n)<<endl;

    return 0;
}