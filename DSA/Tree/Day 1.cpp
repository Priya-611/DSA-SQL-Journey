
// Tree
/*
A tree is a non-linear, hierarchical data structure made up of nodes connected by edges.
Each tree has a root node, and every node can have zero or more child nodes.

-> One node is designated as the root.
-> Every node (except root) has one parent.
-> Nodes can have 0 or more children.
-> No cycles (unlike graphs).
-> Recursive nature — every child node is itself a tree.



| Term       | Explanation                                         |
| ---------- | --------------------------------------------------- |
| Node       | Basic unit containing data                          |
| Root       | Top node in a tree                                  |
| Parent     | A node that has children                            |
| Child      | A node that descends from another                   |
| Leaf       | A node with no children                             |
| Edge       | Connection between two nodes                        |
| Subtree    | A tree within a tree                                |
| Height     | Number of edges on longest path from node to a leaf |
| Depth      | Number of edges from root to a node                 |
| Level      | Depth + 1 (root is at level 1)                      |
| Degree     | Number of children a node has                       |


Types of Trees:
1. Binary Tree -> Each node has at most 2 children (left, right).

2. Binary Search Tree (BST) -> Left child < root < Right child

3. Full Binary Tree -> Every node has 0 or 2 children

4. Complete Binary Tree -> All levels filled except possibly the last, and filled left to right

5. Perfect Binary Tree -> All internal nodes have 2 children and all leaves are at the same level

6. Balanced Binary Tree -> Difference between left and right subtree height is at most 1 for all nodes

7. N-ary Tree -> Each node can have at most N children

8. Skewed Tree -> All nodes have only one child (like a linked list)
    There are two types:
    Left Skewed: All nodes only have a left child.
    Right Skewed: All nodes only have a right child.

Binary Tree Example:
         A         <-- Root
       /   \
      B     C
     / \   / \
    D   E F   G

Root = A
Children of A = B, C
Parent of D = B
Leaves = D, E, F, G
Height of A = 2
Depth of G = 2




Type of Tree Traversal:
1. Depth-First Search (DFS):
   - Pre-order: Visit root, then left subtree, then right subtree.  [Root → Left → Right]
   - In-order: Visit left subtree, then root, then right subtree.  [Left → Root → Right]
   - Post-order: Visit left subtree, then right subtree, then root.  [Left → Right → Root]

2. Breadth-First Search (BFS):
   - Level-order: Visit nodes level by level from top to bottom, left to right. Using Queue

*/

//Traversal
// It follows a preorder style construction: Root → Left Subtree → Right Subtree
#include <iostream>
using namespace std;
struct Node{
    char data;
    Node *left;
    Node *right;
};
Node *create(){   //function return pointer to Node
    cout<<"Enter value: ";
    char val;
    cin>>val;
    if(val == 'X') return NULL;   //if it's 'X', return NULL indicating no node
    else{
        Node* newnode= new Node;
        newnode-> data=val;
        newnode->left=create();  // recursively create left subtree
        newnode->right=create(); // recursively create right subtree
        return newnode; // Return the newly created node
    }
}

void inorder(Node *root){  //left->root->right
    if(root==NULL) return;
    inorder(root->left);    //traverse depth first to the left[get the left most node first]
    cout<<root->data<<" ";
    inorder(root->right);   //traverse depth first to the right[get the right most node last]
}

void preorder(Node *root){   //root->left->right
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);   
    preorder(root->right);
}

void postorder(Node *root){    //left->right->root
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node *root=NULL; 
    root=create();  //call create function to build the tree
    if(root==NULL) cout<<"Failed creation"<<endl;
    else{
        cout<<"Inorder Traversal: ";
        inorder(root);                 //D B E A C F
        cout<<endl;
        cout<<"Preorder Traversal: ";
        preorder(root);                //A B D E C F
        cout<<endl;
        cout<<"Postorder Traversal: ";
        postorder(root);               //D E B F C A        
    }

}

//input:
// A B D X X E X X C X F X X
//output:
//         A
//        / \
//       B   C
//      / \    \
//     D   E    F




// Even though recursion creates many nodes, only one node — the very first one — is returned to root in main().
// Node* root = create();  // stores the pointer to the first node only






//Level Order Insertion 
#include<iostream>
#include<queue>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

Node *create(){   
    cout<<"Enter value: ";
    char val;
    cin>>val;
    if(val == 'X') return NULL;   
    else{
        Node* newnode= new Node;   //creating a new node
        newnode-> data=val;
        newnode->left=create();   // recursively creating left subtree
        newnode->right=create();  // recursively creating right subtree
        return newnode; 
    }
}

void levelOrder(Node *root){
    if(root==NULL) return;

    queue<Node*> q;

    q.push(root);  //pushing the root node into the queue

    while(!q.empty()){   //till the queue is not empty
        Node *curr=q.front();  //store front node
        q.pop();     //pop the front node from the queue

        cout<<curr->data<<" ";    //print the data of curr(front)
        if(curr->left!=NULL){
            q.push(curr->left);   //push left child
        }
        if(curr->right!=NULL){
            q.push(curr->right);  //push right child
        }
    }
}

int main(){
    Node *root=NULL;
    root=create();  //creating the tree and storing the root pointer
    cout<<"Level Order Traversal: ";
    levelOrder(root);
    cout<<endl;
    return 0;
}

// Input: A B C D E X X F X X X X X
// Level Order Traversal: A B C D E F 






// Building Binary Tree using Array input

// For 0 based indexing:
// left child would be at 2*i+1
// right child would be at 2*i+2

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;

    Node(char val){
        data=val;
        left=right=NULL;
    }
};

Node *buildFromArray(vector<char>&v, int i){
    if(i>=v.size() || v[i]=='X') return NULL;

    Node *root=new Node(v[i]);
    root->left=buildFromArray(v , 2*i+1); 
    root->right=buildFromArray(v , 2*i+2);
    return root;
}

void levelOrder(Node *root){
    if(root==NULL) return;

    queue<Node*> q;

    q.push(root);  //pushing the root node into the queue

    while(!q.empty()){   //till the queue is not empty
        Node *curr=q.front();  //store front node
        q.pop();     //pop the front node from the queue

        cout<<curr->data<<" ";    //print the data of curr(front)
        if(curr->left!=NULL){
            q.push(curr->left);   //push left child
        }
        if(curr->right!=NULL){
            q.push(curr->right);  //push right child
        }
    }
}

int main(){
    int n;
    cout<<"Enter no. of nodes: ";
    cin>>n;

    vector<char> arr(n);
    cout<<"Enter characters: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    Node *root=buildFromArray(arr,i); //pass array and index as 0 
    cout<<"Level Order Traversal: ";
    levelOrder(root);  //printing level order traversal
    cout<<endl;
    return 0;
}


//  A B C D X E F X X X X X X
// Level Order Traversal: A B C D E F 





