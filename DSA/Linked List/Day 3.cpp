// Doubly Linked List : It's like a Singly Linked List but each node has two pointers

// [prev] <-> [ data ] <-> [ next ]

// prev points to the previous node
// next points to the next node

// Each node stores data.
// Each node stores a pointer to the next node (next).
// And a pointer to the previous node (prev)


// This allows:
//  Traversing forward
//  Traversing backward
//  Easier insert/delete at both ends



//creation
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *prev;
    struct link *next;
};
struct link *start=NULL, *node, *current;
void create(){
    cout<<"Enter -1 to stop: ";
    do{
        int x;
        cin>>x;
        if(x==-1) break;
        node=new link();
        node->data=x;
        node->next=NULL;
        node->prev=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;  //the prev of node will have current i.e. the current value (address)
            current=node;        //now current will point to the node(the new current element)


        }

    }while(true);
}
void display_forward(){
    link *ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }

}
void display_backward(){
    link *ptr=start;

    //move to the last node ( i.e. node whose next is null) 
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    //once reached the last node
    //traverse the LL backward 
    //till it's != NULL  keep printing and move to previous node
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
}
int main(){
    create();
    cout<<"\nForward traversal: ";
    display_forward();
    cout<<"\nBackward traversal: ";
    display_backward();
}






//insertion
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
    struct link *prev;
};
struct link *start=NULL, *node, *current;

void create(){
    cout<<"Enter -1 to stop: ";
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;
        node->prev=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            node->prev=current;
            current=node;
        }

    }while(true);
}

void insert(){
    int po,x;
    cout<<"Enter position: ";
    cin>>po;
    cout<<"Enter value: ";
    cin>>x;
    node=new link();
    node->data=x;
    node->next=NULL;
    node->prev=NULL;


    //if element is to be inserted at the starting
    if(po==1){
        node->next=start;
        start->prev=node;
        start=node;

    }
    else{
        current=start;
        int i=2;
        
        //traverse to the position
        while(i<po && current!=NULL){
            current=current->next;
            i++;
        }

        if (current==NULL ){
            cout<<"Position is out bound ";
            return;
        }

        link *ptr=current->next;
        //general working for inserting node

        node->prev = current;          //Set new node’s prev pointer to point to the current node
        node->next = ptr;    //Set new node’s next pointer to point to current’s next node
        current->next = node;          //link current’s next pointer to the new node

        //if node is inserted somewere in between( do update prev pointer of ptr)
        if(ptr!=NULL){
            ptr->prev = node;    //Update the next node’s prev pointer to point back to the new node
        }

        }


        // [current] ⇆ [new node] ⇆ [ptr]


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
    insert();
    display();
}







//Deletion:

//1. by position
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
    struct link *prev;
};
struct link *start=NULL, *node, *current;

void create(){
    cout<<"Enter -1 to stop: ";
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;
        node->prev=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            node->prev=current;
            current=node;
        }

    }while(true);
}

void deletion(){
    int po;
    cout<<"Enter position: ";
    cin>>po;

    
    if(po==1){
        start=start->next;
        start->prev=NULL;

    }
    else{
        current=start;
        link *ptr = current->next;
        int i=2;

        //traverse to the position to be deleted
        while(i<po && ptr!=NULL){ 
            current=current->next;
            ptr=ptr->next;
            i++;
        }
        
        if(ptr==NULL) {
            cout<<"Position out of bound";
            return;
        }

        //if last position is to be deleted
        if(ptr->next == NULL){ 
            current->next=NULL;
            delete ptr;
        }
        //else ( if middle elements are to be deleted)
        else{
            current->next = ptr->next;  //set the next of current a next of ptr
            ptr->next->prev = current;  //set prev of ptr's next as current
            delete ptr;
        }

        //ptr is just current->next
        //can work wothout ptr too 
        /** current->next = current->next->next;
        current->next->next->prev = current; **/ 

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
    deletion();
    display();
}






//2. by value
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
    struct link *prev;
};
struct link *start=NULL, *node, *current;

void create(){
    cout<<"Enter -1 to stop: ";
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;
        node->prev=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            node->prev=current;
            current=node;
        }

    }while(true);
}

void deletion(){
    int x;
    cout<<"Enter value: ";
    cin>>x;

    
    if(start->data==x){
        start=start->next;
        start->prev=NULL;

    }
    else{
        current=start;
        link *ptr = current->next;

        //traverse till ptr is NULL
        while( ptr!=NULL){

            //if data is found check the position
            if(ptr->data==x ){
                //if last node is to be deleted
                if(ptr->next==NULL){
                current->next=NULL;
                }
                //if middle element is to be deleted
                else{
                    current->next = ptr->next;  //set the next of current a next of ptr
                    ptr->next->prev = current;  //set prev of ptr's next as current
                } 
                delete ptr;
                return;
            }
            //increment current and ptr till data is found
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
    deletion();
    display();
}






//WAP to find length of doubly LL
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
    struct link *prev;
};
struct link *start=NULL, *node, *current;

void create(){
    cout<<"Enter -1 to stop: ";
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;
        node->prev=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            node->prev=current;
            current=node;
        }

    }while(true);
}
int find_len(){
    current=start;
    int count=0;
    while (current!=NULL){
        count++;
        current=current->next;

    }
    return count;
}
int main(){
    create();
    cout<<"Length of Doubly LL is: "<<find_len()<<endl;
}

