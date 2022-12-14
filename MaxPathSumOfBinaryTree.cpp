#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, n) for (int i = a; i < n; i++)

struct node{
    int data;
    node *left;
    node *right;
};


// Time Complexity: O(N).
// Reason: We are doing a tree traversal.

// Space Complexity: O(N)
int maxSum(node *root, int &maxi){
    if (root == NULL)
        return 0;

    
    int leftSum = max(0,maxSum(root->left, maxi));
    int rightSum = max(0,maxSum(root->right, maxi));

    int val=root->data;

    maxi=max(maxi,leftSum+rightSum+val);

    return val + max(leftSum, rightSum);
}

int maxPathSum(node * root) {
  int maxi = INT_MIN;
  maxSum(root, maxi);
  return maxi;

}


int main(){





    return 0;
}