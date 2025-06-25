// deletion in DCLL

//1. by position: 
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
    struct link *prev;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            node->prev=start;
            current=node;
        }
        else{
            start->prev=node;
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
void deleteByPos(){
    int po;
    cout<<"Enter the position: ";
    cin>>po;
   
    // if deleting from beginning
    if(po==1){
        link *temp=start;
        link *last=start->prev;
        start=start->next;
        last->next=start;
        start->prev=last;

    }
    else{
        current=start;
        int i=2;

        //traverse and find the position
        while(i<po){
            current=current->next;
            i++;
        }

        //if deleting from the last position
        if(current->next->next==start){
            current->next=start;  //current will directly point to start
            start->prev=current;   //prev of start points to current
            return;
        }

        //if deleting from the middle position
        current->next=current->next->next; //next of current directly points to node by skipping 1 pos
        current->next->prev=current;   //prev of node next to urrent points to current
    }
    
}
void display(){
    link *ptr=start;
    //usiing do-while loop here
    // We always want to print at least the head and stop once we're back at the start
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=start);
}
int main(){
    create();
    deleteByPos();
    display();
}





//2. by Value: 
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
    struct link *prev;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            node->prev=start;
            current=node;
        }
        else{
            start->prev=node;
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
void deleteByVal(){
    int x;
    cout<<"Enter the value: ";
    cin>>x;
   
    // if deleting from beginning
    if(start->data==x){
        link *last=start->prev;
        link *temp=start;
        start=start->next;
        last->next=start;
        start->prev=last;
    }
    else{
        link *ptr=start;
        current=ptr->next;

        while(current!=start){
            //if value is found at current
            if(current->data==x ){
                ptr->next=current->next;
                current->next->prev=start;
                return;
            } 
            ptr=ptr->next;
            current=current->next;
        }
    
    }
    
}
void display(){
    link *ptr=start;
    //usiing do-while loop here
    // We always want to print at least the head and stop once we're back at the start
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=start);
}
int main(){
    create();
    deleteByVal();
    display();
}




//Examples:
//Q) Searching value in DCLL
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
    struct link *prev;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            node->prev=start;
            current=node;
        }
        else{
            start->prev=node;
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
int search(){
    int x;
    cout<<"Enter value for searching: ";
    cin>>x;
    link *ptr=start;
    int pos=1;
    do{
        if(ptr->data==x) return pos;
        ptr=ptr->next;
        pos++;
    }while(ptr!=start);
    return -1;
}

int main(){
    create();
    cout<<"Value found at :"<<search();
}





//Q) Inserting value in sorted DCLL in sorted position
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
    struct link *prev;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            node->prev=start;
            current=node;
        }
        else{
            start->prev=node;
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
void sortedinsert(){
    int x;
    cout<<"Enter value for inserting: ";
    cin>>x;
    node=new link();
    node->data=x;
    
    link *ptr=start;

    //inserting before start(head)
    //[last] -> [node] ->[start]
    if(x<start->data){
        link *last =start->prev;
        last->next=node;
        node->prev=last;
        node->next=start;
        start->prev=node;
        start=node;
        return;
    }

    //inserting in between
    while(ptr->next!=start){
        //inserting netween ptr and temp
        //[ptr] -> [node] -> [temp]
        if(ptr->next->data >= x){
            link *temp=ptr->next;  //a temp pointer pointing to next of ptr
            ptr->next=node;
            node->prev=ptr;
            node->next=temp;
            temp->prev=node;
            return;

        }
        ptr=ptr->next;   //increment
    }

    //ptr has reached at the end
    //inserting at the end (if value is greater than all other node)
    node->next=start;
    node->prev=ptr;
    ptr->next=node;
    start->prev=node;
    
}
void display(){
    link *ptr=start;
    //usiing do-while loop here
    // We always want to print at least the head and stop once we're back at the start
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=start);
}
int main(){
    create();
    sortedinsert();
    display();
}





//Q) delete middle value in single traversal
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
    struct link *prev;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            node->prev=start;
            current=node;
        }
        else{
            start->prev=node;
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->prev=current;
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
void deleteMiddle(){
    if(start==NULL || start->next==start){
        cout<<"List is too short";
        return;
    }
    link *fast=start;
    link *slow=start;

    // Move fast 2 steps, slow 1 step until fast completes circle
    while(fast->next!=start && fast->next->next!=start){
        fast=fast->next->next;    //fast move by two position
        slow=slow->next;         //slow move my one position
    }
    //slow now points to middle
    // let's delete slow 

    slow->prev->next=slow->next;
    slow->next->prev = slow->prev;

    // If the middle node was the start, update start
    if(slow==start){
        start=slow->next;
    }
    
    delete slow;  // Free memory of deleted node
    
}
void display(){
    link *ptr=start;
    //usiing do-while loop here
    // We always want to print at least the head and stop once we're back at the start
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=start);
}
int main(){
    create();
    deleteMiddle();
    display();
}


