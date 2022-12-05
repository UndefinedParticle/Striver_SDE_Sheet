#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)



/*Time Complexity: O ( n x n ) x 4    
Reason: Worst-case – We will be making each fresh orange rotten in the grid 
and for each rotten orange will check in 4 directions

Space Complexity: O ( n x n )
Reason: worst-case –  If all oranges are Rotten, 
we will end up pushing all rotten oranges into the Queue data structure*/
int rottenOranges(vector<vector<int>> &grid){
    int m=grid.size();
    int n=grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    int visited[m][n];
    int countFresh=0;
    loop(i,0,m){
        loop(j,0,n){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j]=2;
            }else{
                visited[i][j]=0;
            }

            if(grid[i][j]==1){
                countFresh++;
            }
        }
    }

    int dRow[]={-1,0,1,0};
    int dCol[]={0,1,0,-1};
    int maxT=0;
    int cnt=0;
    while( !q.empty() ){

        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        maxT = max(maxT, t);
        q.pop();

        loop(i,0,4){
            int nRow=row + dRow[i];
            int nCol=col + dCol[i];
            if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && visited[nRow][nCol] ==0 && grid[nRow][nCol]==1){
                q.push({{nRow,nCol},t+1});
                visited[nRow][nCol]=2;
                cnt++;
            }
        }        


    }

    if(cnt != countFresh) return -1;

    return maxT;


}



int main(){

    cout<<"Row size: ";int m;cin>>m;
    cout<<"Column size: ";int n;cin>>n;
    cout<<"Grid:\n";
    vector<vector<int>> grid;
    loop(i,0,m){
        vector<int> vt;
        loop(j,0,n){
            int x;cin>>x;
            vt.emplace_back(x);
        }
        grid.push_back(vt);
    }



    return 0;
}