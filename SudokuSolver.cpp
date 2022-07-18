#include<bits/stdc++.h>
using namespace std;


bool isValid(vector<vector<char>> &board,int row,int col,char ch){
    for(int i=0;i<9;i++){
        if(board[i][col]==ch){
            return false;
        }

        if(board[row][i]==ch){
            return false;
        }

        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)]==ch){
            return false;
        }
    }

    return true;
}


// Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, 
// we have 9 possible numbers.

// Space Complexity: O(1), since we are refilling the given board itself, 
// there is no extra space required, so constant space complexity.
bool sudokuSolver(vector<vector<char>> &board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(isValid(board,i,j,ch)){
                        board[i][j]=ch;
                        if(sudokuSolver(board)){
                            return true;
                        }else{
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}



int main(){

    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    sudokuSolver(board);
    cout<<"Solution:\n";
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }



    return 0;
}