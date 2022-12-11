#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)


struct node{
    int data;
    node *left;
    node *right;
};


// Time Complexity: O(N) 
// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space
int maxDepth(node* root,int &maxi) {
        if(root == NULL) return 0; 
        
        int leftHeight= maxDepth(root->left,maxi); 
        int rightHeight= maxDepth(root->right,maxi); 
        maxi=max(maxi,leftHeight+rightHeight);
        return 1 + max(leftHeight, rightHeight); 
}

int diameterOfBinaryTree(node* root) {
        int diameter = 0;
        maxDepth(root, diameter);
        return diameter;
}





int main(){



    return 0;
}