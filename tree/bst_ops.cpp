/*
    Input:
    q                                  //num queries
    i n 8 3 10 1 6 14 4 7 13           // i: insert n: num of nodes followed by nodes
    s 14                               // s: search followed by value to search
    d 4                                // d: delete followed by value to delete
    p                                  // p: inorder print of bst
*/

#include <bits/stdc++.h>
using namespace std;

typedef struct Tree {
    int val;
    struct Tree *right;
    struct Tree *left;
} bst;

bst * bst_new_node_init(int val){
    bst *new_node = new bst;
    new_node->val = val;
    new_node->right = new_node->left = NULL;
    return new_node;
}

bst * bst_insert(bst *t, int val) {
    if(t == NULL){
        return bst_new_node_init(val);
    }
    if(val >  t->val){
        t->right = bst_insert(t->right, val);     
    } else if(val < t->val){
        t->left = bst_insert(t->left, val);
    } else {
        cout<<"already inserted"<<endl;
    }
    return t;
}
void bst_print_in_order(bst *t){
    if(t == NULL)
        return;
    bst_print_in_order(t->left);
    cout<<t->val<<" ";
    bst_print_in_order(t->right); 
}

bst * bst_search(bst *t, int val) {
    if(t == NULL)
        return NULL;
    if(val >  t->val){
        t = bst_search(t->right, val);     
    } else if(val < t->val){
        t = bst_search(t->left, val);
    } else {
        cout<<"entry found"<<endl;
        return t;
    }
    return t;
}

/*
** Case 1. Delete a Leaf Node in BST
**    Directly delete the node
** Case 2. Delete a Node with Single Child in BST
**    Copy the child to the node and delete the node. 
** Case 3. Delete a Node with Both Children in BST
**    Copy contents of the inorder successor/predessesor to the node, 
**    and delete the inorder successor.
*/
void bst_delete(bst *t, int val){
    if(t == NULL)
        return;
    if(val == t->val){
        if((t->right == NULL) && (t->left == NULL)){ //case 1: leaf node
            delete t;
            return;
        }
        if((t->right == NULL) || (t->left == NULL)){ //case 2: node with single child
            bst * del_node = t;
            t = (t->right)?t->right:t->left;
            delete del_node;
            return;
        }
        if((t->right != NULL) && (t->left != NULL)){ //case 3: node with both child
            bst * next_node = t->right;
            while(next_node->left != NULL){
                next_node = next_node->left;
            }
            t->val = next_node->val;
            delete next_node;
            return;
        }
    } else if(val >  t->val){
        bst_delete(t->right, val);     
    } else {
        bst_delete(t->left, val);
    }
    return;

}

int main(){
    bst *t = NULL;
    int num_queries = 0;
    cin>>num_queries;
    while(num_queries--){
         char q;
         cin >> q;
         switch (q){
             case 'i': //Insert
             {
                 int n = 0;
                 cin>>n;
                 for(int i=0;i<n;i++){
                     int data;
                     cin>>data;
                     if (t == NULL)
                         t = bst_insert(t,data);
                     else
                         bst_insert(t,data);    
                 }
                 break;
             }
             case 's': //search
             {
                 int srch_key = 0;
                 cin >> srch_key;
                 bst *node = bst_search(t,srch_key);
                 if(node == NULL) {
                     cout<<"not found"<<endl;
                 }else {
                     cout<<node->val<<endl;
                 }
                 break;
             }
            case 'p':
            {
                 bst_print_in_order(t); 
                 break;
            }
            case 'd':
            {
                int del_val = 0;
                cin>>del_val;

                bst_delete(t, del_val);
                break;
            }
            default:
            {
                cout<<"invalid operation"<<endl;
            }
        }
    }
    return 0;
}