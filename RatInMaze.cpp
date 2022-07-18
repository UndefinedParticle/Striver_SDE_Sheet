#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(4^(m*n)), 
// because on every cell we need to try 4 different directions.

// Space Complexity:  O(m*n) ,
// Maximum Depth of the recursion tree(auxiliary space)
void ratInMaze(int i,int j,vector<vector<int>> &maze,vector<vector<int>> &visited,vector<string> &ans,string path,int n){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }

    //Up
    if(i-1>=0 && visited[i-1][j]==0 && maze[i-1][j]==1){
        visited[i][j]=1;
        ratInMaze(i-1,j,maze,visited,ans,path+'U',n);
        visited[i][j]=0;
    }

    //Down
    if(i+1<n && visited[i+1][j]==0 && maze[i+1][j]==1){
        visited[i][j]=1;
        ratInMaze(i+1,j,maze,visited,ans,path+'D',n);
        visited[i][j]=0;
    }

    //Left
    if(j-1>=0 && visited[i][j-1]==0 && maze[i][j-1]==1){
        visited[i][j]=1;
        ratInMaze(i,j-1,maze,visited,ans,path+'L',n);
        visited[i][j]=0;
    }

    //Right
    if(j+1<n && visited[i][j+1]==0 && maze[i][j+1]==1){
        visited[i][j]=1;
        ratInMaze(i,j+1,maze,visited,ans,path+'R',n);
        visited[i][j]=0;
    }


}


// Time Complexity: O(4^(m*n)), 
// because on every cell we need to try 4 different directions.

// Space Complexity:  O(m*n) ,
// Maximum Depth of the recursion tree(auxiliary space).
void ratInMaze1(int i,int j,vector<vector<int>> &maze,vector<vector<int>> &visited,int di[],int dj[],vector<string> &ans,string path,int n){
    if(i==n-1 && j==n-1){
        ans.push_back(path);
        return;
    }
    string direction="UDLR";
    for(int ind=0;ind<4;ind++){
        int nextI=i+di[ind];
        int nextJ=j+dj[ind];
        if(nextI>=0 && nextJ>=0 && nextI<n && nextJ<n && visited[nextI][nextJ]==0 && maze[nextI][nextJ]==1){
            visited[i][j]=1;
            ratInMaze1(nextI,nextJ,maze,visited,di,dj,ans,path + direction[ind],n);
            visited[i][j]=0;
        }
    }
}




int main(){

    cout<<"Size of The Maze: ";int n;cin>>n;
    vector<vector<int>> maze;
    cout<<"Elements:\n";
    for(int i=0;i<n;i++){
        vector<int> vt;
        for(int j=0;j<n;j++){
            int x;cin>>x;
            vt.push_back(x);
        }
        maze.push_back(vt);
    }

    vector<vector<int>> visited;
    for(int i=0;i<n;i++){
        vector<int> vt;
        for(int j=0;j<n;j++){
            vt.push_back(0);
        }
        visited.push_back(vt);
    }

    vector<string> ans;
    ratInMaze(0,0,maze,visited,ans,"",n);

    cout<<"Paths:\n";
    if(ans.size()==0){
        cout<<"-1\n";
    }else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }

    int di[4]={-1,+1,0,0};
    int dj[4]={0,0,-1,+1};

    vector<string> ans1;
    ratInMaze(0,0,maze,visited,ans1,"",n);
     cout<<"Paths:\n";
    if(ans1.size()==0){
        cout<<"-1\n";
    }else{
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i]<<endl;
        }
    }






    return 0;
}





