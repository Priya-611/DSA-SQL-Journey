//Creation of Linked List (without fixing the size)

#include<iostream>
using namespace std;
struct link {
    int data;
    struct link *next;
};
struct link *start=NULL, *node,*current;

void create(){
    cout<<"Enter -1 to stop ";
    //loop works until user enter -1 to stop taking input
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;
        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }while(true);
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
    display();
}







//Insertion in LL
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
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

        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }

    }while(true);
}
void insert(){
    int po;
    cout<<"Enter the position to insert: ";
    cin>>po;
    cout<<"Enter the element: ";
    node=new link();
    cin>>node->data;
    node->next=NULL;

    //for 1st position
    if (po==1){
        node->next=start;    //node will point to the start
        start=node;      //node is the new start
    }

    //otherwise: 
    else{
        current=start;//we'll move the current pointer till the position for insertion
        int i=2;
        while(i<po){
            current=current->next;
            i++;
        }
        node->next=current->next;
        current->next=node;

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
    insert();
    display();
}


// example : [ 10 ] → [ 20 ] → [ 30 ] → NULL
// Goal: Insert 99 at position 3
// Steps        current points to	      i	       i < po	         Action
// initially    Node 10 (position 1)	i = 2	   2 < 3 → true	     Move to next
// Step 1	    Node 20 (position 2)	i = 3	   3 < 3 → false	 Stop loop
// Insert	     current is Node 20			                         Insert new node after Node 20









//Deletion in Singly LL

//1. delete from position

#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
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

        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }

    }while(true);
}
void deletion(){
    int po;
    cout<<"Enter the position to delete: ";
    cin>>po;

    //for 1st position
    if (po==1){
        start=start->next;      //node is the new start
    }

    //otherwise: 
    else{
        current=start;//we'll move the current pointer till the position for insertion
        int i=2;
        while(i<po){
            current=current->next;
            i++;
        }
        current->next=current->next->next; //  we'll  set the next pointer to the next to next node

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






//2. delete a particular element
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
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

        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }

    }while(true);
}
void deletion(){
    int x;
    cout<<"Enter the element to delete: ";
    cin>>x;

    //for 1st position
    if (start->data == x){
        start=start->next;      //node is the new start
    }

    //otherwise: 
    else{
        link *ptr=start;
        current=ptr->next;//we'll move the current pointer till the position for insertion
        while(current!=NULL){
            if(current->data == x){
                ptr->next=current->next;
                break;
            }
            ptr=ptr->next;
            current=current->next;
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








//merge two linked list 
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
};
struct link *start1=NULL, *start2=NULL, *start3=NULL, *node, *current;

void create(link *&st){
    cout<<"Enter -1 to stop: ";
    do{
        int n;
        cin>>n;
        if(n==-1) break;
        node=new link();
        node->data=n;
        node->next=NULL;

        if(st==NULL){
            st=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }

    }while(true);
}

void merge(link *s1, link *s2){
    //when both lists have element
    while(s1!=NULL && s2!=NULL){
        node=new link ();
        if(s1->data < s2->data){  //make node with the smallest value
            node->data = s1->data;
            s1=s1->next;   //increment
        }
        else {
            node->data = s2->data;
            s2=s2->next;
        }
        node->next=NULL;

        //creation of merged LL (start3)
        if(start3==NULL){
            start3=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
    }

    //if s1 (List 1) still have elements
    while(s1!=NULL){
        node=new link();
        node->data = s1->data;
        if(start3==NULL){
            start3=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
        s1 = s1->next;
    }

    //if s2 (List 2) still have elements
    while(s2!=NULL){
        node=new link();
        node->data = s2->data;

        if(start3==NULL){
            start3=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }
        s2 = s2->next;
    }

}

void display(link *s3){
    struct link *ptr=s3;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main(){
    cout<<"Enter the first list\n";
    create(start1);
    cout<<"Enter the second list\n";
    create(start2);
    merge(start1, start2);
    display(start3);
}





//WAP to create single  LL & delete x nodes after y nodes
//skip Y delete X
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link * next;
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

        if(start==NULL){
            start=node;
            current=node;
        }
        else{
            current->next=node;
            current=node;
        }

    }while(true);
}

void deleteXNodes(){
    int x,y;
    cout<<"Enter y (positions to skip): ";
    cin>>y;
    cout<<"Enter x (no. of nodes to delete): ";
    cin>>x;
    
    link *ptr=start;
    current=ptr->next;

//if no elements are skipped ,, we'll move the start pointer so as to delete x nodes
    if(y==0){
        //delete all x nodes
        for(int j=0;j<x;j++){
            start=start->next;
        }
    }
    else{
        //move till y (i.e. skip all y values )
        for(int i=0;i<y-1;i++){
            ptr=ptr->next;
            current=current->next;
        }

        //delete all x nodes
        for(int j=0;j<x;j++){
            current=current->next;
        }
        ptr->next=current;
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
    deleteXNodes();
    display();
}



