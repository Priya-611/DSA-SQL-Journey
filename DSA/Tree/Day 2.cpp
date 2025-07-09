// Binary Search Tree(BST)
/*
For every node:
Left subtree contains only nodes less than the node
Right subtree contains only nodes greater than the node

       40
      /  \
    30    60
   /     /  \
  20    50   70
Inorder Traversal = sorted order: 20 30 40 50 60 70
*/



//Insertion: 
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* create(int num){
    Node *newnode=new Node();
    newnode->data=num;
    newnode->left=newnode->right=NULL;
    return newnode;
}

Node *insert(Node *root,int num){
    if(root==NULL) return create(num);    // If tree is empty, create root

    // Recursively insert into left or right subtree based on BST property
    if(num < root->data){
        root->left=insert(root->left,num);
    }
    else if(num > root->data){
        root->right=insert(root->right,num);
    }
    return root;
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
    cout<<"Enter no. of nodes: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];       //88 77 55 99 76 54 66
        root=insert(root, arr[i]);  // Insert into BST and update root
    }
    cout<<"Inorder traversal: ";
    inorder(root);      //54 55 66 76 77 88 99 

    return 0;
}






//Deletion :
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

Node *getSucc(Node *root){  //get minimum value from right subtree
    root=root->right;  //move to right subtree

    while(root!=NULL && root->left!=NULL){
        root=root->left;    //get smallest value (left)
    }
    return root;
}

Node *delNode(Node*root, int num){
    if(root==NULL) return root;

    if(num < root->data) root->left = delNode(root->left,num);
    else if(num > root->data) root->right = delNode(root->right,num);
    else {   //root->data == num  i.e. root is to be deleted  
        if(root->left == NULL){  //if no left child hold right child (new root)
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){   //if no right child hold left child (new root)
            Node *temp=root->left;
            delete root;
            return temp;
        }

        //if node has two children ,find inorder successor (get min value)
        Node *succ=getSucc(root);
        root->data=succ->data;   //replacing root's value by succ's data
        //now deleted succ's value from it's original position
        root->right=delNode(root->right , succ->data);//it will keep searching right subtree till it gets succ->data ,which is to be deleted as its value is already copied in root->data

    }
    return root;
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

    cout<<"Inoder Traversal: ";
    inorder(root);

    root=delNode(root,18);  //deleting 18

    cout<<"Inoder Traversal: ";
    inorder(root);
}





//Delete Minimum Node in BST
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

Node *getSucc(Node *root){  //get minimum value from right subtree
    root=root->right;  //move to right subtree

    while(root!=NULL && root->left!=NULL){
        root=root->left;    //get smallest value (left)
    }
    return root;
}

Node *delMinNode(Node*root){
    if(root==NULL) return root;
    if(root->left == NULL){  //delete root (no left child present)
        Node *temp=root->right;
        delete root;
        return temp;
    }
    root->left=delMinNode(root->left);  //Recursively call delMinNode on the left child
    return root;
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

    cout<<"Inoder Traversal: ";
    inorder(root);

    root=delMinNode(root);  //deleting minimum element

    cout<<"Inoder Traversal: ";
    inorder(root);
}






//Count Nodes in BST
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

int count(Node *root){
    if (root==NULL) return 0;
    int rtc=count(root->right);  //count all nodes in right subtree
    int lft=count(root->left);   //count all nodes in left subtree
    return rtc+lft+1;  //adding 1 to count root
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
    int nodeCount=count(root);
    cout<<"No. of total Nodes : "<<nodeCount<<endl;
}





//Sum of Nodes in BST
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

int Nodesum(Node *root){
    if (root==NULL) return 0;
    
    return root->data+ Nodesum(root->right) + Nodesum(root->left);  //adding 1 to count root
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
    int sum=Nodesum(root);
    cout<<"Sum of all Nodes : "<<sum<<endl;
}





//Count Leaf Nodes in BST
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

int countLeafNode(Node *root){
    if (root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)  return 1;
    return countLeafNode(root->right) + countLeafNode(root->left);   
    
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
    int nodeCount=countLeafNode(root);
    cout<<"No. of Leaf Nodes : "<<nodeCount<<endl;
}





//Sum of Leaf Nodes in BST
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

int leafNodeSum(Node *root){
    if (root==NULL) return 0;
    if (root->left==NULL && root->right==NULL) return root->data;
    return leafNodeSum(root->right) + leafNodeSum(root->left);  //adding 1 to count root
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
    int sum=leafNodeSum(root);
    cout<<"Sum of Leaf Nodes: "<<sum<<endl;
}




//Deleting nodes having value more than average in BST
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

int sumNodes(Node *root){   //find sum of nodes
    if(root==NULL) return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);

}

int countNode(Node *root){   //find total no. of nodes
    if (root==NULL) return 0;
    return countNode(root->right) + countNode(root->left) +1;   
    
}

Node *delNodeGreaterThanAvg(Node *root,int avg){
    if(root==NULL) return root;
    root->left=delNodeGreaterThanAvg(root->left, avg);
    root->right=delNodeGreaterThanAvg(root->right, avg);
    if(root->data > avg){    //if root's value is greater than average(delete it)
        if(root->left==NULL){     //if left child is null return the right and delete node
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){    //if right child is null return the left and delete node
            Node* temp=root->right;
            delete root;
            return temp;
        }

        //if root has both left and right child (find inorder successor)
        Node *temp=root->right;   //go to right subtree
        while(temp!=NULL && temp->left!=NULL){   //find the left most node(smallest)
            temp=temp->left;
        }

        root->data=temp->data;  //replace root's data with temp's data
        root->right=delNodeGreaterThanAvg(root->right, temp->data);   //delete temp's data from right subtree
    }
    return root;
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

    int avg = sumNodes(root)/countNode(root);
    root=delNodeGreaterThanAvg(root,avg);

    cout<<"Inorder traversal: ";
    inorder(root);    
    return 0;
}


