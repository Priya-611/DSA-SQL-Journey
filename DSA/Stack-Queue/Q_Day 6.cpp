// Deque: Double Ended Queue. 
// -> Linear data structure where elements can be:
// -> Inserted and deleted from both ends — front and rear.


// I. Using Array
#include<iostream>
using namespace std;

const int size=8;
int deque[size];
int front=-1;
int rear=-1;

void enqueue_front(){
    if((rear+1)%size==front){
        cout<<"Overflow!!\n";
        return;
    }
    cout<<"Enter element:";
    int n;
    cin>>n;
    if(front==-1 && rear==-1) front=rear=0;
    else if(front==0) front=size-1;  //if front is at the beginning, wrap around to the end
    else front--;  //decrement front to insert at the front(because front is probaby at the end of the array)
    deque[front]=n;


}

void enqueue_back(){
    if((rear+1)%size==front){
        cout<<"Overflow!!\n";
        return;
    }
    cout<<"Enter element:";
    int n;
    cin>>n;
    if(front==-1 && rear==-1) front=rear=0;
    else if(rear==size-1) rear=0;  //if rear is at the end, wrap around to the beginning
    else rear++;
    deque[rear]=n;

}

void dequeue_front(){
    if(front==-1 && rear==-1){
        cout<<"Underflow!!\n";
        return;
    }
    cout<<"Item deleted: "<<deque[front]<<endl;
    if(front==rear) front=rear=-1;
    else if(front==size-1) front=0;  //if front is at the end, wrap around to the beginning
    else front++;  //increment front to remove from the front

}

void dequeue_back(){
    if(front==-1 && rear==-1){
        cout<<"Underflow!!\n";
        return;
    }
    cout<<"Item deleted: "<<deque[rear]<<endl;
    if(front==rear) front=rear=-1;
    else if(rear==0) rear=size-1;  //if rear is at the beginning, wrap around to the end
    else rear--;  //decrement rear to remove from the back

}

void display(){
    if(front==-1 && rear==-1){
        cout<<"dequeue is empty!!\n";
        return;
    }
    cout<<"Elements in dequeue are: ";
    int i=front;
    while(i!=rear){
        cout<<deque[i]<<" ";
        i=(i+1)%size;  //circular increment of i
    }
    cout<<deque[rear]<<" ";  //print the last element (rear)
    cout<<endl;
    
}

int main(){
    cout<<"Enter '1' to enqueue in front\nEnter '2' to enqueue in back(rear)\nEnter '3' to dequeue from front\nEnter '4' to dequeue from back\nEnter '5' to display\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue_front();   //to enter an element
                break;
            case 2:
                enqueue_back();  
                break;
            case 3:
                dequeue_front();  
                break;
            case 4:
                dequeue_back();   
                break;
            case 5:
                display();   
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}






// II. Using Linked List
#include<iostream>
using namespace std;

struct link{
    int data;
    struct link *prev;  // pointer to the previous node
    struct link *next;
};
struct link *front=NULL,*rear=NULL,*node;  //front and rear pointers for the dequeue
void enqueue_front(){
    cout<<"Enter element:";
    int n;
    cin>>n;
    node = new link ();
    node->data=n;
    node->prev = NULL;  // new node will be the front, so prev is NULL
    node->next = NULL;  // next will be NULL initially

    if(front==NULL && rear==NULL){
        front=node;
        rear=node;
    }
    else{
        front->prev=node;
        node->next=front;
        front=node;  // move front to the new node 
        
    }


}

void enqueue_back(){
    cout<<"Enter element:";
    int n;
    cin>>n;
    node = new link ();
    node->data=n;
    node->prev = NULL;  // new node will be the front, so prev is NULL
    node->next = NULL;  // next will be NULL initially

    if(front==NULL && rear==NULL){
        front=node;
        rear=node;
    }
    else{
        node->prev=rear;
        rear->next=node;
        rear=node;  // move rear to the new node
        
    }

}

void dequeue_front(){
    if(front==NULL && rear==NULL){
        cout<<"Underflow!!\n";
        return;
    }
    cout<<"Item deleted: "<<front->data<<endl;
    link *temp=front;
    front=front->next;  // move front to the next node
    front->prev=NULL;  // set the prev of new front to NULL
    delete temp;  //free the memory of deleted node


}

void dequeue_back(){
    if(front==NULL && rear==NULL){
        cout<<"Underflow!!\n";
        return;
    }
    cout<<"Item deleted: "<<rear->data<<endl;
    link *temp=rear;
    rear=rear->prev;
    rear->next=NULL;  // set the next of new rear to NULL    delete temp;  //free the memory of deleted node

}

void display(){
    if(front==NULL && rear==NULL){
        cout<<"dequeue is empty!!\n";
        return;
    }
    cout<<"Elements in dequeue are: ";
    link *ptr=front;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;  // move to the next node
    }
    cout<<endl;
    
}

int main(){
    cout<<"Enter '1' to enqueue in front\nEnter '2' to enqueue in back(rear)\nEnter '3' to dequeue from front\nEnter '4' to dequeue from back\nEnter '5' to display\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue_front();   //to enter an element
                break;
            case 2:
                enqueue_back();   
                break;
            case 3:
                dequeue_front();   
                break;
            case 4:
                dequeue_back();   
                break;
            case 5:
                display();   
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}






// III. Using STL

/*
| Operation       | Description                 |
| --------------- | --------------------------- |
| `push_front(x)` | Insert `x` at the front     |
| `push_back(x)`  | Insert `x` at the rear      |
| `pop_front()`   | Remove from the front       |
| `pop_back()`    | Remove from the rear        |
| `front()`       | Get the front element       |
| `back()`        | Get the last (rear) element |
| `isEmpty()`     | Check if the deque is empty |
| `size()`        | Get the number of elements  |
*/








