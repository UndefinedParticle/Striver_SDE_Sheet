#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left;
    node *right;
};

vector<vector<int>> levelOrder(node *root){
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);
    int flag=1;
    while(!q.empty()){
        int sz=q.size();
        vector<int> row(sz);
        loop(i,0,sz){
            node *temp=q.front();
            q.pop();

            int index=(flag)? i:(sz-1-i);
            row[index]=temp->data;

            if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
        ans.push_back(row);
        flag=!flag;        
    }

    return ans;
}

int main(){

    return 0;
}