 /*
 Given the root of a binary tree, return the length of the diameter of the tree.
 The diameter of a binary tree is the length of the longest path between any two 
 nodes in a tree. This path may or may not pass through the root.
 
 The length of a path between two nodes is represented by the number of edges between them.

Solution:
We can see that diameter of the tree can be defined as left subtree height + right subtree 
height from the Curving Point. So, the idea to find the Curving Point is, consider every node
 in the tree as a curving point and calculate the diameter for every curving point and return
  the maximum of all diameters.
 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1

Time : O(n)
Space: O(1)
*/
#include <bits/stdc++.h>

using namespace std;

/* Definition for a binary tree node.
 */

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} node_t;

node_t * new_node(int val) {
    node_t * node = new node_t;
    node->left = node->right = NULL;
    node->val = val;
    return node; 
}

//Level order traversal
node_t * insert(node_t  *root, int data) {
    if(!root) {
        root = new_node(data);
        return root;
    }
    
    list<node_t *> q;
    q.push_back(root);
    while(!q.empty()) {
        node_t *t = q.front();
        q.pop_front();
        if(t->left){
            q.push_back(t->left);
        }else{
            t->left = new_node(data);
            break;
        }
        if(t->right){
            q.push_back(t->right);
        }else{
            t->right = new_node(data);
            break;
        }
    }
    return root;
}

int height(TreeNode* root, int& d) {
    if (!root)
        return 0;
    int lh = height(root->left, d);
    int rh = height(root->right, d);
    d = max(d, (lh + rh));
    return (1 + max(lh, rh));
}
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int main() 
{
    int n = 0;
    cin>>n;

    node_t *root = NULL;
    while(n--){
        int data = 0;
        cin>>data;
        root = insert(root, data);
    }

    int res;
    res = diameterOfBinaryTree(root);
        cout<<res<<endl;
    return 0;
}
