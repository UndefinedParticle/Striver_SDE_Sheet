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


int main(){

    cout<<"N: ";int n;cin>>n;

    vector < string > board(n);
      string s(n, '_');
      for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    vector < vector < string >> ans;

    getBoard(0,board,ans,n);
    int i=0;
    for(auto vect:ans){
        cout << "Arrangement " << i + 1 << "\n";
        for(auto it:vect){
            cout<<it<<" ";
            cout<<endl;
        }cout<<endl;
        i++;
    }


    







    return 0;
}