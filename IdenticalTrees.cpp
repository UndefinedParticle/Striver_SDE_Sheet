#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left;
    node *right;
};


// Time Complexity: O(N).
// Reason: We are doing a tree traversal.
// Space Complexity: O(N)
bool isIdentical(node *t1,node *t2){

    if(t1==NULL && t2==NULL){
        return true;
    }else if(t1==NULL || t2==NULL){
        return false;
    }

    return (t1->data==t2->data) && (isIdentical(t1->left,t2->left)) && (isIdentical(t1->right,t2->right));

}

int main(){


    return 0;
}