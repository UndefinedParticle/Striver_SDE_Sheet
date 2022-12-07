#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left,*right;
};


// Time Complexity: O(N)
// Space Complexity: O(H)       
vector<int> bottomView(node *root){
    vector<int> ans;
    if(root==NULL)
        return ans;
    
    map<int,int> mp;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        node *nd=it.first;
        int line=it.second;
        mp[line]=nd->data;
        if(nd->left != NULL){
            q.push({nd->left,line-1});
        }
        if(nd->right != NULL){
            q.push({nd->right,line+1});
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }


    return ans;
}




int main(){




    return 0;
}