#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


struct node{
    int data;
    node* left;
    node *right;
};


// Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space
node* lca(node *root,node* nd1,node *nd2){
    if(root==NULL || root==nd1 || root==nd2){
        return root;
    }

    node *leftTree=lca(root->left,nd1,nd2);
    node *rightTree=lca(root->right,nd1,nd2);
    if(leftTree==NULL){
        return rightTree;
    }else if(rightTree==NULL){
        return leftTree;
    }else{
        return root;
    }
}




int main(){




    return 0;
}