#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)
#define rloop(i,n,a) for(int i=n;i>=a;i--)
#define all(a) a.begin(),a.end()

bool isSafe(int row,int col,vector<string> board,int n){
    int dupRow=row;
    int dupCol=col;
    while(row<n && col>=0){
        if(board[row++][col--]=='Q')
            return false;
    }

    row=dupRow;
    col=dupCol;
    while(col>=0){
        if(board[row][col--]=='Q')
            return false;
    }

    row=dupRow;
    col=dupCol;
    while(row>=0 && col>=0){
        if(board[row--][col--]=='Q')
            return false;
    }

    return true;
}

// Time Complexity: Exponential in nature, since we are trying out all ways.
// To be precise it goes as O
// (N! * N) nearly.

// Space Complexity: O(N^2)
void getBoard(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            getBoard(col+1,board,ans,n);
            board[row][col]='_';
        }
    }


}
// Time Complexity: Exponential in nature since we are trying out all ways, 
// to be precise it is O(N! * N).

// Space Complexity: O(N)
void nQueen(int col,vector<string> &board,vector<vector<string>> &ans,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal,int n){

    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 + (col-row)]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            upperDiagonal[n-1+col-row]=1;
            lowerDiagonal[col+row]=1;
            nQueen(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col]='_';
            leftRow[row]=0;
            upperDiagonal[n-1+col-row]=0;
            lowerDiagonal[col+row]=0;
        }
    }



}



int main(){

    cout<<"N: ";int n;cin>>n;

    vector < string > board(n);
    string s(n, '_');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    vector < vector < string >> ans1;

    getBoard(0,board,ans1,n);
    int i=0;
    for(auto vect:ans1){
        cout << "Arrangement " << i + 1 << "\n";
        for(auto it:vect){
            cout<<it<<" ";
            cout<<endl;
        }cout<<endl;
        i++;
    }


    vector < string > board1(n);
    string s1(n, '_');
    for (int i = 0; i < n; i++) {
        board1[i] = s1;
    }
    vector<int> leftRow(n,0);
    vector<int> upperDiagonal(2*n - 1,0);
    vector<int> lowerDiagonal(2*n - 1,0);

    vector < vector < string >> ans2;

    nQueen(0,board1,ans2,leftRow,upperDiagonal,lowerDiagonal,n);
    i=0;
    for(auto vect:ans2){
        cout << "Arrangement " << i + 1 << "\n";
        for(auto it:vect){
            cout<<it<<" ";
            cout<<endl;
        }cout<<endl;
        i++;
    }





    return 0;
}