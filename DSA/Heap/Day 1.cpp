// Heap:
/*
A complete binary tree (all levels filled except possibly last, which is filled from left to right).

# Heap property:
1. Max Heap: parent >= children
2. Min Heap: parent <= children

# Array representation:
If a node is at index i:    [For node at ith position]
-> Left child: 2*i + 1
-> Right child: 2*i + 2
-> Parent: (i-1)/2

# While Building Heap:
Almost always we use an ARRAY internally to represent a binary heap.
Why?
- A heap is a complete binary tree → no gaps in the tree → we can map nodes to array indices easily.
- Using a linked list would require extra memory for pointers and would be SLOWER to access parent/child.
In practice:
✅ Array is the standard way.
❌ Linked list is not used because: Random access (parent/child) would be O(n) instead of O(1). More overhead with pointers.

So yes, we build a heap usually by:
- Taking an array as input.
- Using that array to store heap elements internally.


Q) How is the binary tree built here?
We don’t physically build a “tree” with nodes and pointers.
Instead:
We imagine a binary tree structure but store it in an array.
For example, array A = [10, 20, 5, 7, 9] is interpreted as:

Index: 0  1  2  3  4
Value:10 20  5  7  9

Tree (complete binary tree view):                     Parent/child relationships:
        10 (A[0])                                     Left child of i: 2*i + 1        
       /    \                                         Right child of i: 2*i + 2
   20(A[1])  5(A[2])                                  Parent of i: (i-1)/2 
   /    \
 7(A[3]) 9(A[4])



Q) Why do we need a Heap? (What is the use?)
A heap is mainly used when we need quick access to the largest or smallest element while still inserting or removing efficiently.
Key points:
- Insert element: O(log n)
- Get min/max: O(1)
- Remove min/max: O(log n)

So, whenever you have a problem like:
- You keep receiving elements
- You often need to know the top K elements
- Or you need to repeatedly take out the smallest/largest
Heap is the best data structure.


# Features of MIN HEAP & MAX HEAP:

| Feature                     | **Min Heap**                                        | **Max Heap**                                       |
| --------------------------- | --------------------------------------------------- | -------------------------------------------------- |
| **Property**                | Parent node ≤ child nodes                           | Parent node ≥ child nodes                          |
| **Root**                    | Always contains the **smallest** element            | Always contains the **largest** element            |
| **Insertion**               | Insert at end, bubble **up** until parent ≤ child   | Insert at end, bubble **up** until parent ≥ child  |
| **Deletion (extract root)** | Removes smallest, then heapify to maintain property | Removes largest, then heapify to maintain property |



# Usage of MIN HEAP & MAX HEAP:

|       Min Heap Usage                                     |     Max Heap Usage                                |
| -------------------------------------------------------- | ------------------------------------------------- |
| Get the smallest element quickly (root is smallest)      | Get the largest element quickly (root is largest) |
| Kth largest element (use a min heap of size k)           | Kth smallest element (use a max heap of size k)   |
| Merge k sorted arrays (pick smallest each time)          | Keep track of top k smallest elements in a stream |
| Dijkstra’s algorithm (always pick smallest distance)     | Schedule tasks by highest priority                |
| Connect ropes with minimum cost (combine smallest ropes) | Sliding window maximum problems                   |
| Sliding window minimum problems                          | Keep track of top k largest elements in a stream  |
| Anytime you need min priority first                      | Anytime you need max priority first               |


*/



// In C++ STL:
/*
- priority_queue is a container adapter that by default uses a Max‑Heap internally. 
- Internally, it uses a vector (array) and the function make_heap, push_heap, pop_heap from <algorithm> to maintain heap property.

You don’t manually build the tree.
You just use:
- priority_queue<int> maxHeap;  // max heap
- priority_queue<int, vector<int>, greater<int>> minHeap

And STL handles:
- Inserting elements
- Keeping them in heap order
- Giving you the largest (or smallest) on top()
- Internally, it is still array-based (using a vector).
*/



//Max Heap Using STL's priority queue

#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> maxHeap;
    maxHeap.push(11);
    maxHeap.push(17);
    maxHeap.push(22);
    maxHeap.push(8);
    maxHeap.push(32);
    maxHeap.push(26);

    cout<<"Max Heap (top): "<<maxHeap.top()<<endl;  //32
    maxHeap.pop();
    cout<<"Next top: "<<maxHeap.top()<<endl;  //26

    while(!maxHeap.empty()){
        cout<<maxHeap.top()<<" ";   //26 22 17 11 8 
        maxHeap.pop();
    }
}

// the order of elements here are in a way that for node i
// left child is at 2*i+1
// right child is at 2*i+2
// and parent at (i-1)/2





//Min Heap using STL's priority queue

#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(11);
    minHeap.push(17);
    minHeap.push(22);
    minHeap.push(8);
    minHeap.push(32);
    minHeap.push(26);

    cout<<"Max Heap (top): "<<minHeap.top()<<endl;  //8
    minHeap.pop();
    cout<<"Next top: "<<minHeap.top()<<endl;  //11

    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";   //11 17 22 26 32 
        minHeap.pop();
    }
}

//here the topmost element [the root] is the minimum amoung all it's children






// Ways to Build a Heap from an array
// There are two common ways:

/*
1. Insertion Method (Repeated Insert)        [while insertion , form heap- tree]
Insert elements one by one into an initially empty heap and heapify-up (percolate up) each time.

Steps:
- Start with an empty heap.
- Take the first element, place it as root.
- Take the next element, place it in next available spot (maintain complete binary tree structure).
- Compare with parent and swap upwards until heap property is satisfied.
- Repeat for all elements.

 Time Complexity: O(n log n)
(because each insertion can take log n time)



2. Heapify / Build-Heap Method (Bottom‑Up)           [first take all elements, form tree and then compare and swap]
Start with the entire array (considered as a complete binary tree) and heapify-down from the last non-leaf node up to root.

Steps:
- Take your input array as it is (no insertion step needed).
- Find the last non-leaf node: index = (n/2) - 1.
- Call heapify() (sift-down) on each node from (n/2)-1 down to 0.
- After this process, the whole array satisfies heap property.

 Time Complexity: O(n)
(much faster for bulk data)

*/



//Insertion 
//Way 1:   [ Insertion Method (Repeated Insert) ]

//MAX HEAP 
#include<iostream>
using namespace std;

int idx=0;
void insert_heap(int a[],int num){
    a[idx]=num;
    int po=idx;  //po will check the current index
    while(po>0 && a[po]> a[(po-1)/2]){  //comparing element with its parent [if it is greater than it's parent, swap it and shift to it's parent to check it]
        swap(a[po],a[(po-1)/2]);
        po=(po-1)/2;   //make po as its parent till po > 0
    }
    idx++;
}

int main(){
    int n,num;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>num;
        insert_heap(a,num);  // forming heap tree while inserting 
    }
    cout<<"Elements in Heap are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}





//MIN HEAP  [only change the condition in while loop]
#include<iostream>
using namespace std;

int idx=0;
void insert_heap(int a[],int num){
    a[idx]=num;
    int po=idx;  //po will check the current index
    while(po>0 && a[po] < a[(po-1)/2]){  //comparing element with its parent [if it is smaller than it's parent, swap it and shift to it's parent to check it]
        swap(a[po],a[(po-1)/2]);
        po=(po-1)/2;   //make po as its parent till po > 0
    }
    idx++;
}

int main(){
    int n,num;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>num;
        insert_heap(a,num);  // forming heap tree while inserting 
    }
    cout<<"Elements in Heap are: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

/*insert_heap()  ->  as the num is inserted, insert it in the array and check if that num is greater(smaller) than its parent, 
if yes, then swap them and go and check if it's(parent's) parent is greater(smaller) thann it(parent)*/





//Way 2:   [ Heapify / Build-Heap Method (Bottom‑Up) ]

//MAX HEAP
#include<iostream>
using namespace std;
void heapify(int a[], int n, int idx){
    int larIdx=idx;
    int l=2*idx+1;   //get the left child 
    int r=2*idx+2;   //get the right child
    if(l<n && a[l] > a[larIdx]) larIdx=l;    // if left child is greater than larIdx , change larIdx value
    if(r<n && a[r] > a[larIdx]) larIdx=r;    // if right child is greater than larIdx , change larIdx value
    
    if(larIdx!=idx){   //if larIdx value has changed now
        swap(a[larIdx],a[idx]);   //swap the value
        heapify(a,n,larIdx);    //heapify the current tree
    }
}
void build_heap(int a[], int n){

    for(int k=(n/2)-1;k>=0;k--){ //loop will extract only parent element [ex-> for 9 elements value of k will be 3,2,1,0 ]
        heapify(a,n,k);  //everytime pass a tree [k is the parent element]
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    
}




//MIN HEAP [only change the condition inside the 'if' inside heapify function ]
#include<iostream>
using namespace std;
void heapify(int a[], int n, int idx){
    int larIdx=idx;
    int l=2*idx+1;   //get the left child 
    int r=2*idx+2;   //get the right child
    if(l<n && a[l] < a[larIdx]) larIdx=l;    // if left child is greater than larIdx , change larIdx value
    if(r<n && a[r] < a[larIdx]) larIdx=r;    // if right child is greater than larIdx , change larIdx value
    
    if(larIdx!=idx){   //if larIdx value has changed now
        swap(a[larIdx],a[idx]);   //swap the value
        heapify(a,n,larIdx);    //heapify the current tree
    }
}
void build_heap(int a[], int n){

    for(int k=(n/2)-1;k>=0;k--){ //loop will extract only parent element [ex-> for 9 elements value of k will be 3,2,1,0 ]
        heapify(a,n,k);  //everytime pass a tree [k is the parent element]
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    build_heap(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    
}



