/*
    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
    Merge all the linked-lists into one sorted linked-list and return it.
    Input:
    3 // = k
    3 // no. of element in first list
    1 4 5 //element in first list
    3 // no. of element in 2nd list
    1 3 4
    2
    2 6
    Output:
    1 1 2 3 4 4 5 6

    Time Complexity: O(N*K*log K), As outer while loop in function mergeKLists() runs 
    log K times and every time it processes N*K elements.
    
    Auxiliary Space: O(N*K), Because recursion is used in SortedMerge() and to merge 
    the final 2 linked lists of size N/2, N recursive calls will be made.
*/

#include <bits/stdc++.h>
using namespace std;

 
struct ListNode 
{
    int val;
    struct ListNode* next;
};
 
// Utility function to create 
// a new node
struct ListNode* newNode(int data)
{
    // Allocate node
    struct ListNode* new_node = new ListNode();
 
    // Put in the data
    new_node->val = data;
    new_node->next = NULL;
 
    return new_node;
}

class Comparator {
public:
    bool operator() ( ListNode* a,  ListNode* b) const {
        if(a && b){
            return a->val > b->val;
        } // Min-heap: smaller values go to the top
        return 0;
    }
};
void insert_back(ListNode * &head, ListNode * &tail, ListNode* &NewNode){
    if(head == NULL) { //first element of the result list
        head = NewNode;
        tail = head;
    } else {    
        tail->next = NewNode;
        tail = tail->next;
    }
}

//Merge K sorted list using map
/*
ListNode* mergeKLists(vector<ListNode*>& lists) {
    map<int, int> m;
    for(int i = 0; i<lists.size(); i++){
        ListNode* tmp = lists[i];
        while(tmp) {
            m[tmp->val]++;
            tmp = tmp->next; 
        }
    }
    ListNode* head = NULL, *tail = NULL;

    for(auto i=m.begin(); i != m.end(); i++) {
        while(i->second--){
            ListNode *node = new ListNode(i->first);
            insert_back(head, tail, node);
        }
    }
    return head;
}
*/

//Merge K sorted list using min heap
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* head = NULL;
    ListNode* tmp = head;

    //min heap
    priority_queue<ListNode * , vector<ListNode* >, Comparator> q;

    //push head nodes for all the k linklist
    for(int i = 0; i<lists.size(); i++){
        if(lists[i]) {
            q.push(lists[i]);
        }
    }

    //Iterate till min heap is empty
    while(!q.empty()){
        ListNode* t = q.top();
        
        //cout<<t->val<<" ";
        q.pop();

        //push next node of the top node of min heap
        if(t->next){
            q.push(t->next);
            t->next = NULL;
        }

        //inserting at the end of the result list
        insert_back(head, tmp, t);
    }
    return head;
}
void print_list(ListNode * head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    ListNode *head;
    int k;
    cin>>k;
    vector<ListNode*> list(k);
    while(k--) {
        int n = 0;
        ListNode * tmp = NULL;
        cin>>n;
        while(n--){
            int val = 0;
            cin>>val;
            if(list[k]){
                tmp->next = newNode(val);
                tmp = tmp->next;
            }else {
                list[k] = newNode(val);
                tmp = list[k];
            }
        }
    }

    head = mergeKLists(list);

    print_list(head);

    return 0;

}
