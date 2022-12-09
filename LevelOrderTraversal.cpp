#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

vector<int> levelOrder(node *root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *temp=q.front();
        q.pop();

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }


        ans.push_back(temp->data);
    }

    return ans;
}

int main(){

    return 0;
}