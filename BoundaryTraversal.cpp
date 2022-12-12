#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left;
    node *right;
};


bool isLeaf(node *root){
    return !(root->left) && !(root->right);
}

void addLeftBoundary(node *root,vector<int> &ans){
    node *cur=root->left;
    while(cur){
        if(!isLeaf(cur)){
            ans.emplace_back(cur->data);
        }
        if(cur->left){
            cur=cur->left;
        }else{
            cur=cur->right;
        }
    }
}

void addRightBoundary(node *root,vector<int> &ans){
    node *cur=root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)){
            temp.emplace_back(cur->data);
        }
        if(cur->right){
            cur=cur->right;
        }else{
            cur=cur->left;
        }
    }

    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

void addLeaves(node *root,vector<int> &ans){
    if(isLeaf(root)){
        ans.emplace_back(root->data);
        return;
    }
    if(root->left){
        addLeaves(root->left,ans);
    }
    if(root->right){
        addLeaves(root->right,ans);
    }
}


/*Time Complexity: O(N).
Reason: The time complexity will be O(H) + O(H) + O(N) 
which is ≈ O(N)

Space Complexity: O(N)*/
vector<int> printBoundary(node *root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    if(!isLeaf(root)){
        ans.emplace_back(root->data);
    }
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}




int main(){

    return 0;
}