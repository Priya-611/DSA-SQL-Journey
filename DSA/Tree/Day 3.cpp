
//Searching key in BST
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node *create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);
    if(num<root->data) root->left=insert(root->left,num);
    else if(num>root->data) root->right=insert(root->right,num);

    return root;
}

bool search(Node *root,int key){
    if(root==NULL) return false;

    if(key==root->data) return true;
    if(key<root->data) return search(root->left,key);  //if key < root->data ,, move to left
    else return search(root->right,key);     //if key > root->data ,, move to right
}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=NULL;

    int n;
    cout<<"Enter elements (-1 to stop): ";
    while(true){
        cin>>n;
        if(n==-1) break;
        root=insert(root,n);
    }

    int key;
    cout<<"enter key to search: ";
    cin>>key;

    cout<<"Inorder traversal: ";
    inorder(root); 
    cout<<endl;

    if(search(root,key)) cout<<key<<" is present in BST\n";
    else cout<<key<<" is not present in BST\n"; 


    return 0;
}




//Finding Height of tree 
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node *create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);
    if(num<root->data) root->left=insert(root->left,num);
    else if(num>root->data) root->right=insert(root->right,num);

    return root;
}

int height(Node *root){
    if(root==NULL) return -1;

    int lft=height(root->left);   // Recursively get left subtree height
    int rht=height(root->right);  // Recursively get right subtree height
    return 1 + max(lft,rht);      // Add 1 for current node
}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=NULL;

    int n;
    cout<<"Enter elements (-1 to stop): ";
    while(true){
        cin>>n;
        if(n==-1) break;
        root=insert(root,n);
    }

    cout<<"Inorder traversal: ";
    inorder(root); 
    cout<<endl;

    cout<<"Height of tree: "<<height(root);


    return 0;
}





//Finding min and max value 
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node *create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);
    if(num<root->data) root->left=insert(root->left,num);
    else if(num>root->data) root->right=insert(root->right,num);

    return root;
}

int findMin(Node *root){
    if(root==NULL) return -1;
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int findMax(Node *root){
    if(root==NULL) return -1;
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node *root=NULL;

    int n;
    cout<<"Enter elements (-1 to stop): ";
    while(true){
        cin>>n;
        if(n==-1) break;
        root=insert(root,n);
    }

    cout<<"Inorder traversal: ";
    inorder(root); 
    cout<<endl;

    cout<<"Minimum value in BST is "<<findMin(root)<<endl;
    cout<<"Maximum value in BST is "<<findMax(root)<<endl;
    

    return 0;
}





//Lowest Common Ancestor (LCA)
// The LCA of two nodes p and q is the lowest (deepest) node that has both p and q as descendants.
/* 
Idea:
If both p and q are less than root → LCA is in left subtree
If both are greater than root → LCA is in right subtree
If one is on each side → current root is LCA
*/

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node *create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);
    if(num<root->data) root->left=insert(root->left,num);
    else if(num>root->data) root->right=insert(root->right,num);

    return root;
}

int findLCA(Node *root,int p, int q){
    if(root==NULL) return -1;
    if(p<root->data && q<root->data) return findLCA(root->left,p,q);    // If both p and q are smaller than root
    if(p>root->data && q>root->data) return findLCA(root->right,p,q);   // If both p and q are greater than root
     // If p and q are on different side, then root is LCA
    return root->data;
}

int main(){
    Node *root=NULL;

    int n;
    cout<<"Enter elements (-1 to stop): ";
    while(true){
        cin>>n;
        if(n==-1) break;
        root=insert(root,n);
    }
    int p,q;
    cout<<"Enter value of p and q: ";
    cin>>p>>q;

    int lca=findLCA(root,p,q);
    if (lca==-1)cout<<"LCA not found\n";
    else cout<<"LCA of "<<p<<" and "<<q<<" is: "<<lca<<endl;
    

    return 0;
}




//Find kth smallest element
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node *right;
};

Node *create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;

    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);
    if(num<root->data) root->left=insert(root->left,num);
    else if(num>root->data) root->right=insert(root->right,num);

    return root;
}

int kthSmallest(Node *root,int k ,int &count){
    if(root==NULL) return -1;
    int left=kthSmallest(root->left,k,count);  //keep traversing to the left subtree
    if(left!=-1) return left;   //when left has reached to the end start returning
    count++;    //while returning keep increasing count 
    if(count==k) return root->data;  //when count==k stop and return that data

    //if still not found start seraching the right subtree
    return k kthSmallest(root->right,k,count);
}

int main(){
    Node *root=NULL;

    int n;
    cout<<"Enter elements (-1 to stop): ";
    while(true){
        cin>>n;
        if(n==-1) break;
        root=insert(root,n);
    }
    int k;
    cout<<"Enter value of k: ";
    cin>>k;

    int count=0;
    cout<<"Kth smallest element is: "<<kthSmallest(root,k);
    
    return 0;
}


