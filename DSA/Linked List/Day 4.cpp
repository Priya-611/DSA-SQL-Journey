//Circular Linked List: The last node’s next pointer points back to the first node.
// So, you can keep traversing endlessly in a circle.



//Types:
// 1. Singly Circular Linked List (SCLL):
//     Each node points next → last node’s next points back to head.
//     No prev.

// 2. Doubly Circular Linked List (DCLL):
//     Each node has next and prev.
//     prev of head points to tail; next of tail points to head.






//Creation of SCLL

#include<iostream>
using namespace std;
struct link{
    int data;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            current=node;
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
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
    display();
}





//insertion in SCLL
#include<iostream>
using namespace std;
struct link{
    int data;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            current=node;
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
            node->next=start;   //next of new node points back to start(head)
            current=node;
        }
    }while(true);
}
void insertion(){
    int po, x;
    cout<<"Enter the position: ";
    cin>>po;
    cout<<"Enter the value: ";
    cin>>x;

    node=new link();
    node->data=x;

    // if inserting at the beginning
    if(po==1){
        link *last=start;
        //traversiing till the end so that the last node can now point to the new node
        while(last->next!=start){
            last=last->next;
        }
        node->next=start;  //pointing to old start
        last->next=node;  //last node point to new inserted node(as it is the new head)
        start=node;       //node is the new head(start)
    }
    else{
        current=start;
        int i=2;

        //traverse and find the position
        while(i<po){
            current=current->next;
            i++;
        }

        //if inserting at the last position
        if(current->next==start){
            current->next=node;  //current will point to node
            node->next=start;   //new node points back to start (head)
            return;
        }

        //if inserting at the middle position
        node->next=current->next;  //next of node points to next of current 
        current->next=node; //next of current points to node
    
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
    insertion();
    display();
}






// deletion in SCLL

//1. by position: 
#include<iostream>
using namespace std;
struct link{
    int data;
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
        if(start==NULL){
            start=node;
            node->next=node; // circular link: points to itself i.e. points back to head
            current=node;
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
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
        link *last=start;
        //traversiing till the end so that the last node can now point to the new start(head)
        while(last->next!=start){
            last=last->next;
        }

        last->next=start->next;  //next of last will now point to next of start
        start=start->next;       // 2nd node will become the new start
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
            return;
        }

        //if deleting from the middle position
        current->next=current->next->next; //next of current directly points to node by skipping 1 pos
    
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
            current=node;
        }
        else{
            current->next=node;  //the next of current will have node i.e. the node value (address)
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
        link *last=start;
        //traversiing till the end so that the last node can now point to the new start(head)
        while(last->next!=start){
            last=last->next;
        }
        start=start->next;       // 2nd node will become the new start
        last->next=start;  //next of last will now point to new start

    }
    else{
        link *ptr=start;
        current=ptr->next;

        while(current!=start){
            //if value is found at current
            if(current->data==x ){
                ptr->next=current->next;
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




//Doubly Circular LL

// creation of DCLL
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

        if(start==NULL){
            start=node;
            current=node;
            node->next=start;  //next of node and prev of node both will point to start
            node->prev=start;
            
        }
        else{
            start->prev=node;  //prev of start points to node
            current->next=node;  //current of next also points to node
            node->prev=current;  //prev of node points to current 
            node->next=start; //next of node points back to start
            current=node;
        }

    }while(true);
}
void display(){
    link *ptr=start;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
   }while(ptr!=start);
}
int main(){
    create();
    display();
}





// insertion in DCLL
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

        if(start==NULL){
            start=node;
            current=node;
            node->next=start;
            node->prev=start;
            
        }
        else{
            start->prev=node;
            current->next=node;
            node->prev=current;
            node->next=start;
            current=node;
        }

    }while(true);
}
void insertion(){
    int po,x;
    cout<<"Enter position: ";
    cin>>po;
    cout<<"Enter value: ";
    cin>>x;

    node=new link();
    node->data=x;
    if(po==1){
        link *last=start->prev; //will get the last node
        
        node->next=start;  //next of node points to start as it will become the new start
        node->prev=last;  //prev of node points to last
        last->next=node;   //last of next points to new node
        start->prev=node;  //prev of start points to new node
        start=node;    //node become the new start
    }
    else{
        current=start;
        int i=2;
        while(i<po ){
            current=current->next;
            i++;
        }
        //modify node->next, node->prev, current->next, current->next->next
        node->next=current->next;
        current->next->prev=node;
        current->next=node;
        node->prev=current;

    }

}
void display(){
    link *ptr=start;
    do{
        cout<<ptr->data<<" ";
        ptr=ptr->next;
   }while(ptr!=start);
}
int main(){
    create();
    insertion();
    display();
}



