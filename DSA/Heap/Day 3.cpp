// Heap Sort:
// Heap Sort is a comparison-based sorting algorithm that uses the heap data structure.

/*
Steps:
- Build a Max Heap from the input array.
- Repeatedly:
    : Swap the root (largest element) with the last element in the heap.
    : Reduce the heap size by 1.    [i.e. repeatedly heapify by reducing size by 1 (initially except last element, then except last 2 elements, then last 3 and so on...)]
    : Heapify the root to maintain max-heap property.

Time Complexity:
- Building the heap: O(n)
- Each extraction: O(log n), repeated n times → O(n log n) overall.

In-place: Yes, no extra array needed.
*/





#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;

    while(l<n && a[l] > a[larIdx]) larIdx=l;
    while(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[idx],a[larIdx]);
        heapify(a,n,larIdx);
    }

}

void heapSort(int a[], int n){
    for(int k=n/2 -1;k<n;k++){   //build_heap() work
        heapify(a,n,k);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Elements in Max Heap(before) are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    heapSort(a,n);

    //print
    cout<<"Elements in sorted Max Heap are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}



/*heapSort()-> firstly build a max heap tree, then use for-loop to keep swapping first(max) element with the last (then 2nd lst , then 3rd last and so on...) 
and heaoify by passing first element as parent and reducing size by 1 each time (here for heapify each time size is reduced)              */

//if we use min heap initially then we'll get the descending sorted order(reversed)


// Heap Sort is not stable (equal elements might change order).
// It sorts in-place with O(1) extra space.
// Time Complexity = O(n log n).






//Q) Check if this Binary Tree follow Heap property ?
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val): data(val), left(NULL), right(NULL){}
};

Node* buildTree(){  //building binary tree 
    int val;
    cin>>val; //take input value
    if(val==-1) return NULL;  //-1 means no child
    Node* root = new Node(val);

    queue<Node*> q;
    q.push(root);   //push root in queue
    while(!q.empty()){
        Node * curr=q.front();  //accessing front element in queue
        q.pop();
        int l,r;

        cin>>l;   //getting let child and right child for curr Node (front element (each element in queue))
        if(l!=-1){
            curr->left=new Node(l);
            q.push(curr->left);
        }


        cin>>r;
        if(r!=-1){
            curr->right=new Node(r);
            q.push(curr->right);
        }
    }
    return root;   //tree is build
}

class Solution{
    public:

    int countNodes(Node* root){  //will count total Nodes
        if(root==NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isComplete(Node* root, int i, int total ){ //chek for completeness of binary tree
        if(root==NULL) return true; 
        if(i>=total) return false;  // [That would indicate: There’s a “gap” somewhere before in the tree,structure doesn't fil CBT]
        return isComplete(root->left, 2*i+1, total) && isComplete(root->right, 2*i+2, total);  //keep checking 
    }

    bool maxHeapProperty(Node *root){ //check if they follow max heap property
        if(root->left==NULL && root->right==NULL) return true;
        if(root->right==NULL){  //if no right child ,compare left child   [NOTE: right child should exist only if left child exists]
            return (root->data >= root->left->data);
        }
        //if both child exist 
        bool left=maxHeapProperty(root->left);
        bool right=maxHeapProperty(root->right);

        return left && right && (root->data >= root->left->data) && (root->data >= root->right->data );
    }

    bool isHeap(Node* root){      //initiallyfunction to be called from main
        int total=countNodes(root);
        return isComplete(root,0,total) && maxHeapProperty(root);
    }

};

int main(){
    Node * root=buildTree();  //will call buildTree()

    Solution ob; //object for Solution class
    if(ob.isHeap(root)) cout<<"This Binary tree follow Heap property "<<endl;
    else cout<<"This Binary tree doesn't follow Heap property "<<endl;


}


/*   
Node* buildTree() -> Build a binary tree from level-order input. It reads the first integer → create a root node (if it’s -1, return NULL because tree is empty).
Use a queue to build the tree level by level , Push the root into the queue.
While the queue is not empty:
-----Take (pop) the front node from the queue → this is the current parent.
-----Read two integers (l and r) → left and right child values.
-----If l is not -1, create a new node as left child and push it into the queue.
-----If r is not -1, create a new node as right child and push it into the queue.

Continue until input is exhausted.
Return the root of the tree.




isHeap(Node* root) -> Main checker to see if a binary tree is a valid Max-Heap. First, count total nodes: total = countNodes(root).
Then, check: Is it complete? → isComplete(root, 0, total)
Does it satisfy max-heap property? → maxHeapProperty(root)
If both are true → return true (this is a valid Max Heap).
Otherwise → return false.




countNodes(Node* root) -> Count the total number of nodes in the tree. If root is NULL, return 0 (no nodes here).
Otherwise, return 1 + countNodes(left subtree) + countNodes(right subtree). This recursively adds up all nodes in the tree.



isComplete(Node* root, int i, int total) -> Check if the tree is a Complete Binary Tree (CBT).
Each node is given an index (like array representation of a CBT):
Root at index 0, Left child at 2*i+1, Right child at 2*i+2.
If you ever try to assign a node to an index >= total number of nodes, it means the tree is not complete → return false.  
[That would indicate: There’s a “gap” somewhere before in the tree,structure doesn't fil CBT]

Recursively check for both left and right children with updated indices. If every node fits within these indices, then the tree is complete.



maxHeapProperty(Node* root) -> Check if the tree follows the Max-Heap property. For every node, its value should be greater than or equal to its children.
Base cases:
If both children are NULL, it’s valid.
If only left child exists, check root->data >= root->left->data  [checking only left node because as it is CBT right child must exist only if left child is there]

Otherwise:
Recursively check left and right subtrees (maxHeapProperty(root->left) and maxHeapProperty(root->right)).
Also check the current node’s value is greater than both children’s values. Combine all with && to ensure the property holds everywhere.

 
*/




//Decrease‑Key (or Increase‑Key) in a Heap
#include<iostream>
using namespace std;

void heapify(int a[],int n,int idx){ //heapify(top-down approach) [kepp swapping if large value is found]
    int larIdx=idx;
    int l=2*idx+1;
    int r=2*idx+2;

    if(l<n && a[l] > a[larIdx]) larIdx=l;
    if(r<n && a[r] > a[larIdx]) larIdx=r;

    if(larIdx!=idx){
        swap(a[idx],a[larIdx]);
        heapify(a,n,larIdx);
    }

}

void insertHeap(int a[], int &n, int value){ //insert at idx and then bubble-up[bottom-up approach]
    a[n]=value;  
    int i=n;
    n++;

    while(i>0 && a[i]> a[(i-1)/2]){
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}

void increaseKey(int a[], int idx, int val){  //change value at idx and then bubble-up
    a[idx]=val;
    //bubble-up
    while(idx>0 && a[idx]> a[(idx-1)/2]){
        swap(a[idx],a[(idx-1)/2]);
        idx=(idx-1)/2;
    }

}

void decreaseKey(int a[],int n, int idx, int val){ //change value at idx an then heapify [top down]
    a[idx]=val;

    heapify(a,n,idx); 
}

void displayHeap(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a[100];
    int n=0;

    insertHeap(a,n,10);
    insertHeap(a,n,20);
    insertHeap(a,n,15);
    insertHeap(a,n,40);
    insertHeap(a,n,50);

    cout<<"Elements in Max Heap after insertion: ";
    displayHeap(a,n);

    cout<<"Increase key at index 2 to 55\n";
    increaseKey(a,2,55);
    cout<<"Heap after 1st change: ";
    displayHeap(a,n);


    cout<<"Decrease key at index 0 to 8\n";
    decreaseKey(a,n,0,8);

    cout<<"Heap after deletion: ";
    displayHeap(a,n);

}

/*
insertHeap() ->  will insert the value at position and check if it's parent is smaller then child (current) ,swap then 
and increase n(size)


heapify() -> perform heapify operation i.e it will keep checking if any children hold greater value , if so swap them


increasekey() -> change the value at given index and bubble-up [i.e. keep checking the parent and swap accordingly]


decrease key() -> change the value at given index and heapify 


displayHeap() ->  will display current array elements
*/







//Kth-largest value
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findKthLargest(vector<int> &a, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int num: a){
        minHeap.push(num);
        if(minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    vector<int> a(n);
    
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>a[i];
    
    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<k<<"th largest element is: "<<findKthLargest(a,k)<<endl;

}

/*finKthLargest() ->  keep pushing element from vector in minHeap [after pushing element , it will get in heap order itself]
now keep checking size each time and if size gets bigger delete the top(smallest) , 
now when size of vector is k  i.e.  k elements are left the top most element(now smallest) is kth largest element


nums = [3,2,1,5,6,4], k = 2

Step through:
- Push 3 -> heap = [3]
- Push 2 -> heap = [2,3] (min-heap root=2)
- Push 1 -> heap = [1,3,2], size=3 > k -> pop smallest (1)
  heap now = [2,3]
- Push 5 -> heap = [2,3,5], size=3 > k -> pop smallest (2)
  heap now = [3,5]
- Push 6 -> heap = [3,5,6], size=3 > k -> pop smallest (3)
  heap now = [5,6]
- Push 4 -> heap = [4,6,5], size=3 > k -> pop smallest (4)
  heap now = [5,6]

Final heap = [5,6], smallest = 5
Answer = 5

*/




/*  if i build ,maxHeap[priority_queue<int> maxHeap] with same logic it will give kth smallest element  */

