#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)



struct TreeNode{
    int data;
    TreeNode *left,*right;
};

int maxWidth(TreeNode *root){

    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size=q.size();
        int curMin=q.front().second;
        int leftMost,rightMost;
        loop(i,0,size){
            int curId=q.front().second - curMin;
            TreeNode *temp=q.front().first;
            q.pop();
            if(i==0){
                leftMost=curId;
            }
            if(i==size-1){
                rightMost=curId;
            }
            if(temp->left){
                q.push({temp->left,2*curId+1});
            }
            if(temp->right){
                q.push({temp->right,2*curId +2});
            }
        }
        ans=max(ans,rightMost-leftMost+1);
    }
    

    return ans;
}




int main(){




    return 0;
}