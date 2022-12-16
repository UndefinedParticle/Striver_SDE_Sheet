#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *prev=NULL;

// Time Complexity: O(N)
// Reason: We are doing a simple preorder traversal.

// Space Complexity: O(N)
/*void flatten1(node *root){
    if(root==NULL){
        return;
    }
    flatten1(root->right);
    flatten1(root->left);

    root->right = prev;
    root->left=NULL;
    prev = root;
}*/


void flatten2(node *root){
    if(root==NULL){
        return;
    }
    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node *cur=st.top();
        st.pop();

        if(cur->right !=NULL){
            st.push(cur->right);
        }
        if(cur->left !=NULL){
            st.push(cur->left);
        }
        if(!st.empty()){
            cur->right=st.top();
        }
        cur->left=NULL;
    }
}


// Time Complexity: O(N)
// Reason: Time complexity will be the same as that of a morris traversal

// Space Complexity: O(1)
void flatten3(node *root){

    node *cur=root;
    while(cur != NULL){
        if(cur->left == NULL){
            cur=cur->right;
        }else{
            node *prev=cur->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=cur->right;
            cur->right=cur->left;
            cur->left=NULL;
        }
    }

}

int main(){

    return 0;
}