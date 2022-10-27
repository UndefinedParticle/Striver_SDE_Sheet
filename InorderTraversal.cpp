#include<iostream>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


struct node{
    int data;
    node *left,*right;
};

void preOrder(node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void inOrder(node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){








    return 0;
}