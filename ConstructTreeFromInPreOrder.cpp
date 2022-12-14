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
node* consturctTree(vector<int> &preOrder,int preStart,int preEnd,vector<int> &inOrder,int inStart,int inEnd,map<int,int> &mp){

    if(preStart>preEnd || inStart>inEnd){
        return NULL;
    }
    node *root=new node(preOrder[preStart]);
    int inIndex=mp[root->data];
    int inSize=inIndex-inStart;

    root->left=consturctTree(preOrder,preStart+1,preStart+inSize,inOrder,inStart,inIndex-1,mp);
    root->right=consturctTree(preOrder,preStart+inSize+1,preEnd,inOrder,inIndex+1,inEnd,mp);


    return root;
}

node* buildTree(vector<int> &preOrder,vector<int> &inOrder){
    int preStart=0,preEnd=preOrder.size()-1;
    int inStart=0,inEnd=inOrder.size()-1;

    map<int,int> mp;
    for(int i=inStart;i<=inEnd;i++){
        mp[inOrder[i]]=i;
    }

    return consturctTree(preOrder,preStart,preEnd,inOrder,inStart,inEnd,mp);
}


int main(){

    cout<<"Number Of Nodes: ";int n;cin>>n;
    cout<<"InOrder Elements:\n";
    vector<int> inOrder;
    loop(i,0,n){
        int x;cin>>x;
        inOrder.emplace_back(x);
    }

    cout<<"PreOrder Elements:\n";
    vector<int> preOrder;
    loop(i,0,n){
        int x;cin>>x;
        preOrder.emplace_back(x);
    }

    buildTree(preOrder,inOrder);

    return 0;
}