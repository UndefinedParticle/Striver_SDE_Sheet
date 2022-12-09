#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

void getPaths(node *root,vector<int> &ds,vector<vector<int>> &ans){

    if(root==NULL){
        return;
    }

    ds.push_back(root->data);
    if(root->left==NULL || root->right==NULL){
        ans.push_back(ds);
    }

    getPaths(root->left,ds,ans);
    getPaths(root->right,ds,ans);
    ds.pop_back();

}

int getHeight(node *root){
    vector<int> ds;
    vector<vector<int>> ans;
    getPaths(root,ds,ans);
    int maxi=0;
    for(auto it:ans){
        int size=it.size();
        maxi=max(maxi,size);
    }
    return maxi;
}

int maxDepth(node* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
}


int main(){


    return 0;
}