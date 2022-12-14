#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

// Time Complexity: O(N)
// Reason: We are doing simple tree traversal and 
// changing both root1 and root2 simultaneously.

// Space Complexity: O(N)
bool isSymmetric(node *root1,node *root2){

    if(root1==NULL || root2==NULL){
        return root1==root2;
    }

    return (root1->data==root2->data) && (isSymmetric(root1->left,root2->right)) && (isSymmetric(root1->right,root2->left));
}

bool symmetric(node *root){
    if(root==NULL) return true;

    return isSymmetric(root->left,root->right);
}

int main(){



    return 0;
}