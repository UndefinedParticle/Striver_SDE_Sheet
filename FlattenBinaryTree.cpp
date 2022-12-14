#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
node prev=new node();
prev=NULL;
void flatten(node *root){
    if(root==NULL){
        return;
    }
    flatten(root->right);
    flatten(root->left);

    root->right=prev;
    root->left=NULL;
    prev=root;
}