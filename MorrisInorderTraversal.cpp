#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};


// Time Complexity: O(N).
// Space Complexity: O(1)
// Reason: We are not using recursion.
vector<int> getInorder(node* root){

    vector<int> ans;
    node *cur=root;
    while(cur != NULL){
        if(cur->left == NULL){
            ans.push_back(cur->data);
            cur=cur->right;
        }else{
            node *prev=cur->left;
            while(prev->right &&prev->right != cur){
                prev=prev->right;
            }
            if(prev->right ==NULL){
                prev->right=cur;
                cur=cur->left;
            }else{
                prev->right=NULL;
                ans.push_back(cur->data);
                cur=cur->right;
            }
        }
    }

    return ans;
}




int main(){







    return 0;
}