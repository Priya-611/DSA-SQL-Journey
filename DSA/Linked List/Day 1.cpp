// Linked List: A linked list is a linear data structure where each element (node) points to the next.
// Each node has 1. Data  and 2. Pointer to next node
// no fixed size --- no contiguous memory --- easy insertion and deletion
// we use linked list as arrays have fixed size 
// LL have efficient memory use 
// flexible data structure


// Types of Linked list 
// Singly Linked List: one pointer -> next
// Doubly Linked List: two pointers -> prev and next
// Circular Linked List: last node points back to head


// we'll be using structure here
// struct (structure) is a user-defined data type in C++
// groups different pieces of data together under on name
// structure is used to combine related data that logically belong together
/**
struct Student {
    int rollNumber;
    float marks;
    char grade;
};
here Student structure has : 
rollNumber , marks and grade
**/


// a struct can also have pointers as variable

// struct Node {
//     int data;     // value stored
//     Node* next;   // pointer to next Node
// };
// Each [ data | next ] is a Node.


// to make pointer to a Node
// struct Node *start=NULL;    //here start is a pointer to a Node intialised to NULL



// They are two different things:
// 1. Node *start = new Node() : creates a new Node in heap memory (new returns the address of that Node.)
// 2. Node *start = NULL; : declares a pointer variable and sets it to NULL (that points to a Node type)



//for accessing the struct variable
// For Normal struct variable	--> use dot(.) operator,, ex: n.data
// For Pointer to struct --> use arrow(->) operator,, ex: p->data
// p->data is the same as (*p).data





//creating a singly LL
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;   //here next is a pointer pointing to struct
};
struct link *start=NULL, *node, *current;  
// start is initially pointing to NULL, 
// *node will be used to create node further and 
// current keeps the record of currently pointed node

void create(){
    int n;
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();  //node is a address of struct type (each time an element is entered, a new node is created)
        cin>>node->data;  //element gets inserted into data part of each node
        node->next=NULL;

        if(start==NULL){  //this will only work in 1st iteration when start is NULL
            start = node;
            current = node;
            //now both start and current are pointing to node
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
            current=node;  //now current will point to the node(the new current element)
        }
    }
}

void display(){
    struct link *ptr=start;  //a temporary pointer pointing to start of the linked list
    while(ptr!=NULL){
        cout<<ptr->data<<" ";  //print the data
        ptr=ptr->next;  //go to the next node
    }
}

int main(){
    create();
    display();
}







//find the largest element from a single linked list
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *start=NULL, *node, *current;
void create(){
    int n;
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}

void largestElement(){
    // struct link *ptr=start;
    int lar=start->data; //let's say the 1st element is largest
    current= start->next;  // current will iterate 
    while(current!=NULL){  
        if(current->data > lar){  //if data of current > lar
            lar=current->data;
        }
        current=current->next;
    }
    cout<<lar;
}

int main(){
    create();
    largestElement();
}








//adding all elements in a single linked list
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *start=NULL, *node, *current;
void create(){
    int n;
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}

void addElements(){
    struct link *ptr=start;
    int sum=0;
    while(ptr!=NULL){  
        sum += ptr->data;
        ptr=ptr->next;
    }
    cout<<sum;

}

int main(){
    create();
    addElements();
}






//Sort all the elemenst in ascending order
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *start=NULL, *node, *current;
int n;
void create(){
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}

void sortElements(){
    for(int i=0;i<n;i++){
        struct link *ptr=start;
        current=ptr->next; 
        
        //ptr and current will iterate and compare themselves
        //at the end of one iteration we'll have largest element at the end of LL  
        while(current!=NULL){
            if(current->data < ptr->data) swap(ptr->data,current->data);
            current=current->next;
            ptr=ptr->next;
        }
    }

}
void display(){
    struct link *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    create();
    sortElements();
    display();
}







//creating two singly linked list 
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *start1=NULL, *start2=NULL, *node, *current;

void create(link *&start){    //start is a reference to a pointer to a link node.
    int n;
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}
void display(link *&start){
    struct link *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    create(start1);
    create(start2);
    cout<<endl;
    display(start1);
    display(start2);
}





//link *start -> means start is a pointer to a link node. So, it can hold the address of a node.

//link *&start -> means start is a reference to a pointer to a link node[a reference to actual pointer]. So, if you modify start inside the function, the original pointer you passed in main() also gets updated.






//creating 5 single linked list
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
// start[5] → an array of 5 linked list head pointers

struct link *start[5], *node, *current;
int n;

void create(link *&start){    //start is a reference to a pointer to a link node.
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}
void display(link *&start){
    struct link *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    // Initialize all heads to NULL
    for (int i = 0; i < 5; i++) {
        start[i] = NULL;
    }
    // each start[i] will point to the head of a separate linked list.
    for(int i=0;i<5;i++) create(start[i]);  //create and display are called 5 times
    for(int i=0;i<5;i++) display(start[i]);
}










//print the Linked List in reverse order
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *start=NULL, *node, *current;

void create(){    //start is a reference to a pointer to a link node.
    int n;
    cout<<"Enter the total no. of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        node=new link();
        cin>>node->data;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }
}
void display(link *&start){
    if(start==NULL) return;    //if reached the end of the list, stop recursion.
    display(start->next);   //call display() on the next node, untill you reach the end
    //as soon as you reach the end , the display() before resumes and executes it's last remaining line
    cout<<start->data<<" ";   //after the recursive call, it prints from the last node 
}
int main(){
    create();
    display(start);
}


