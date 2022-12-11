#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{

    int data;
    node *left;
    node *right;

};

int maxDepth(node* root,vector<int> &diff) {
        if(root == NULL) return 0; 
        
        int leftHeight= maxDepth(root->left,diff); 
        int rightHeight= maxDepth(root->right,diff); 
        diff.push_back(abs(leftHeight-rightHeight));
        return 1 + max(leftHeight, rightHeight); 
}

bool diameterOfBinaryTree(node* root) {
        vector<int> diff;
        maxDepth(root, diff);
        for(auto it:diff){
            if(it>1){
                return false;
            }
        }
        return true;;
}



int main(){


    return 0;
}