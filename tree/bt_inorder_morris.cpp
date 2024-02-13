t /*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Use morris traversal. Traversal without recurssion.

Complexity Analysis:

Time complexity: O(n)
The time complexity of the Inorder Morris Traversal algorithm is O(n), where n is the number 
of nodes in the binary tree. This is because each edge of the tree is traversed at most twice:
 once to establish the threaded link and once to traverse the tree.

Space complexity: O(1)

Extra space is only allocated for the ArrayList of size nnn, however the output does not count towards the space complexity.
Example 1:


Input: n = 4
    1,2,3,4
Output: 4 2 1 3
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

//Morris Traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    while (root) {
        if (!root->left) {
            //cout<<root->val;
            res.push_back(root->val);
            root = root->right; //// move to next right node
        } else { //left subtree exists
            TreeNode *r = root->left;
            while(r) {
                if(r->right) { //finding rightmost
                    //cur node is already threaded
                    if(root == r->right){
                        r->right = NULL; //remove thread to prevent loop
                        //cout<<root->val;
                        res.push_back(root->val);
                        root = root->right;
                        break;
                    } else {
                        r = r->right;
                    }
                }else {
                    //creating thread with the current node
                    r->right = root;
                    root = root->left;
                    break;
                }                  
            }
        }
    }
    return res;
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
    vector<int> res;
    res = inorderTraversal(root);
    for(int i=0; i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
