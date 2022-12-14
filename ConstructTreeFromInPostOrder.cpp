#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left;
    node *right;

    node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }

};


// Time Complexity: O(N)
// Assumption: Hashmap returns the answer in constant time.

// Space Complexity: O(N)
node* consturctTree(vector<int> &postOrder,int postStart,int postEnd,vector<int> &inOrder,int inStart,int inEnd,map<int,int> &mp){

    if(postStart>postEnd || inStart>inEnd){
        return NULL;
    }
    node *root=new node(postOrder[postEnd]);
    int inIndex=mp[root->data];
    int inSize=inIndex-inStart;

    root->left=consturctTree(postOrder,postStart,postStart+inSize-1,inOrder,inStart,inIndex-1,mp);
    root->right=consturctTree(postOrder,postStart+inSize,postEnd-1,inOrder,inIndex+1,inEnd,mp);


    return root;
}

node* buildTree(vector<int> &postOrder,vector<int> &inOrder){
    
    int postStart=0,postEnd=postOrder.size()-1;
    int inStart=0,inEnd=inOrder.size()-1;

    map<int,int> mp;
    for(int i=inStart;i<=inEnd;i++){
        mp[inOrder[i]]=i;
    }

    return consturctTree(postOrder,postStart,postEnd,inOrder,inStart,inEnd,mp);
}


int main(){

    cout<<"Number Of Nodes: ";int n;cin>>n;
    cout<<"InOrder Elements:\n";
    vector<int> inOrder;
    loop(i,0,n){
        int x;cin>>x;
        inOrder.emplace_back(x);
    }

    cout<<"postOrder Elements:\n";
    vector<int> postOrder;
    loop(i,0,n){
        int x;cin>>x;
        postOrder.emplace_back(x);
    }

    buildTree(postOrder,inOrder);

    return 0;
}