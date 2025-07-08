
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
        inorder(root);
        cout<<endl;
        cout<<"Preorder Traversal: ";
        preorder(root);
        cout<<endl;
        cout<<"Postorder Traversal: ";
        postorder(root);        
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








