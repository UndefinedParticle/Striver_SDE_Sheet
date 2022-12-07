#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left,*right;
};


// Time Complexity: O(N)

// Space Complexity: O(H)       
// (H -> Height of the Tree)
void helper(node *root,int level,vector<int> &ds){

    if(root==NULL) 
        return;

    if(ds.size()==level){
        ds.push_back(root->data);
    }

    helper(root->right,level+1,ds);
    helper(root->left,level+1,ds);
}


vector<int> rightView(node *root){
    vector<int> ds;
    helper(root,0,ds);
    return ds;
}




int main(){




    return 0;
}