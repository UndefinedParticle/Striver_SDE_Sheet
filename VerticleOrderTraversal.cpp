#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{

    int data;
    node *left,*right;

};


// Time Complexity: O(N*logN*logN*logN)
// Space Complexity: O(N)
vector<vector<int>> verticalTraversal(node* root){
    // we can use vector in the place of multiset 
    map<int,map<int,multiset<int>>> mp;
    queue<pair<node*,pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        node *temp=it.first;
        int vertical=it.second.first;
        int level=it.second.second;
        mp[vertical][level].insert(temp->data);

        if(temp->left){
            q.push({temp->left,{vertical-1,level+1}});
        }
        if(temp->right){
            q.push({temp->right,{vertical+1,level+1}});
        }
    }
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int> row;
            for(auto j: i.second){
                row.insert(row.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(row);
        }

    return ans;
}



int main(){








    return 0;
}