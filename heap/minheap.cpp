/*
QUESTION:
This question is designed to help you get a better understanding of basic heap operations.

There are  types of query:

" " - Add an element  to the heap.
" " - Delete the element  from the heap.
"" - Print the minimum of all the elements in the heap.
NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.

Input Format

The first line contains the number of queries, .
Each of the next  lines contains one of the  types of query.

Constraints


Output Format

For each query of type , print the minimum value on a single line.

Sample Input

STDIN       Function
-----       --------
5           Q = 5
1 4         insert 4
1 9         insert 9
3           print minimum
2 4         delete 4
3           print minimum
Sample Output

4  
9 
Explanation

After the first  queries, the heap contains {}. Printing the minimum gives  as the output. Then, the  query deletes  from the heap, and the  query gives  as the output.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Heap data structure
vector <long> mheap;

//Utility functions
int get_parent_pos(int child_pos) {
    return ((child_pos-1)/2);
}

int get_left_child_pos(int parent_pos) {
    return ((2*parent_pos)+1);
}

int get_right_child_pos(int parent_pos) {
    return ((2*parent_pos)+2);
}

//Get position of the value in the heap array
int get_node_pos(int value) {
    for(int i=0; i<mheap.size();i++) {
        if(mheap[i] == value)
            return i;
    }
    return -1;
}

void swap(int root_pos, int child_pos){
    long tmp = mheap[root_pos];
    mheap[root_pos] = mheap[child_pos];
    mheap[child_pos] = tmp;
}

//Insert in min heap. Time Complexity O(log(n))
void minheap_insert(long value) {

    int parent_pos = 0;
    
    //Inserting at the end
    mheap.push_back(value);

    for(int i = mheap.size()-1; i > 0; ) {
        parent_pos = get_parent_pos(i);

	//Balancing the heap from end to the top
        if(mheap[parent_pos] > mheap[i]) {
            swap(parent_pos, i);
            i = parent_pos;
        }else { 
            break;
        }
    }
}

/*
  Balancing the tree from node_pos to the end od the tree to maintain
  min heap property. Time Complexity O(log(n))
*/
void minheap_heapify(int node_pos) {

    for(int i = node_pos; i < mheap.size(); ) {
	//Get left & right child position of the node
        int left_pos = get_left_child_pos(i);
        int right_pos = get_right_child_pos(i);
        int min_value_pos = 0;
        
	//position is exceeding the heap size then invalid positions
	if((right_pos >= mheap.size()) || (left_pos >= mheap.size()))
            return;
	
	//Getting minimum among the left & right child
        if(mheap[left_pos] < mheap[right_pos]){
            min_value_pos = left_pos;
        }else {
            min_value_pos = right_pos;
        }
        
	//Comparing min child with parent 
        if(mheap[min_value_pos] < mheap[i]) {
            swap(min_value_pos,i);
            i = min_value_pos;
        } else {
            break;
        }
    }
}

//Delete value from minheap. Time complexity: O(n+log(n)).
void minheap_delete(long value) {
    //Getting array index of the value in the heap
    int pos = get_node_pos(value);

    //Swapping that index with the last value of the tree
    swap(pos, (mheap.size()-1));

    //Delete the last element ie., "value" param
    mheap.erase((mheap.end()-1));

    //Balace the tree to maintain min heap properties
    minheap_heapify(pos);
}

//Printing the root of the minheap binary tree
void minheap_print_min() 
{   if(mheap.size() == 0)
        return;
    cout<<mheap[0]<<endl;
}

int main() {
    int q = 0;
    cin>>q;
    while(q--) {
        int query[2] = {0};
        cin>>query[0];
        if(query[0] != 3) { // print minimum query only one input
            cin>>query[1];
        }
        switch(query[0]){
            case 1:
                minheap_insert(query[1]);
                break;
            case 2:
                minheap_delete(query[1]);
                break;
            case 3:
                minheap_print_min();
                break;
            default:
                cout<<"Invalid Query";
        }
    }   
    return 0;
}

