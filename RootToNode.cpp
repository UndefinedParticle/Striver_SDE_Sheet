#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left,*right;
};


// Time Complexity: O(N)
// Space Complexity: O(N)
bool getPath(node *root,int x,vector<int> &ds){

    if(root==NULL){
        return false;
    }
    
    ds.push_back(root->data);
    if(root->data == x){
        return true;
    }
    if(getPath(root->left,x,ds) || getPath(root->right,x,ds)){
        return true;
    }
    ds.pop_back();

    return false;
}


int main(){



    return 0;
}