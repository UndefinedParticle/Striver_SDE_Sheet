#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};


// Time Complexity: O(N)
// Reason: We are doing a simple tree traversal.

// Space Complexity: O(N)
void childrenSum(node *root){

    if(root==NULL){
        return;
    }

    int leftSum=0,rightSum=0;
    if(root->left){
        leftSum+=root->left->data;
    }
    if(root->right){
        rightSum+=root->right->data;
    }

    if(root->data > leftSum+rightSum){
        if(root->left){
        root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }else{
        root->data = leftSum+rightSum;
    }

    childrenSum(root->left);
    childrenSum(root->right);

    int total=0;
    if(root->left){
        total+= root->left->data;
    }
    if(root->right){
        total+= root->right->data;
    }
    if(root->left || root->right){
        root->data = total;
    }

}


int main(){


    return 0;
}