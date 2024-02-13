 /*
 Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:



Input: n = 6
    1,2,3,4,5,6
Output: 1 3 6

Time : O(n)
Space: O(n)
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

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    list<TreeNode *> q;
    q.push_back(root);

    while(!q.empty()) {
    	int count = q.size(); //no. of element on each level
	    for(int i =0;i<count;i++){
	         TreeNode *t = q.front();
	         q.pop_front();

	         if(t && t->left){
	         	q.push_back(t->left);
	         }

	         if(t && t->right){
	         	q.push_back(t->right);
	         }

	         if(t && (i==count - 1)){   
	         	res.push_back(t->val);
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
    res = rightSideView(root);
    for(int i=0; i<res.size();i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
