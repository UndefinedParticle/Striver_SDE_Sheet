#include<bits/stdc++.h>
using namespace std;
#define loop(i,a,n) for(int i=a;i<n;i++)

struct node{
    int data;
    node *left,*right;
};


/*Time Complexity: O(N)
Reason: We are visiting every node thrice therefore time complexity will be O(3*N), 
which can be assumed as linear time complexity.

Space Complexity: O(N)
Reason: We are using three lists and a stack to store the nodes. 
The time complexity will be about O(4*N),
which can be assumed as linear time complexity. */
void oneTraversal(node *root,vector<int> &preOrder,vector<int> &inOrder,vector<int> &postOrder){

    if(root==NULL){
        return;
    }

    stack<pair<node*,int>> st;
    st.push({root,1});
    
    while(!st.empty()){
        auto it=st.top();
        st.pop();

        if(it.second==1){
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left !=NULL){
                st.push({it.first->left,1});
            }

        }else if(it.second==2){
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right !=NULL){
                st.push({it.first->right,1});
            }

        }else{
            postOrder.push_back(it.first->data);
        }

    }
}



int main(){




    return 0;
}