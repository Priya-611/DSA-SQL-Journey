// A queue is a linear data structure that follows the FIFO
/*
FIFO = First In, First Out
(The first element added is the first one to be removed)
-> You can only take the front plate off.
-> You add (enqueue) at the rear and remove (dequeue) from the front

[ 30 | 40 | 50 | 60 | 10 ]
   ↑                   ↑
 front                rear




| Operation      | Description                                        |
| -------------- | -------------------------------------------------- |
| enqueue(x)     | Add element x at the rear (back) of the queue    |
| dequeue()      | Remove and return the element from the front       |
| front()        | Return the element at the front (without removing) |
| rear()         | Return the element at the rear (without removing)  |
| isEmpty()      | Check if the queue is empty                        |
| isFull()       | (for fixed-size queue) Check if queue is full      |



Ways to Implement a Queue:

1. Using Arrays
Simple, but size is fixed.
Enqueue at rear index, dequeue from front index.
Need to shift elements if you don't use circular logic.

2. Using Linked List
No size limit (until memory runs out).
Enqueue at tail, dequeue from head.

3. Using Libraries / Built-in Structures
Python: collections.deque, queue.Queue
Java: Queue interface (e.g., LinkedList, ArrayDeque)
C++: std::queue

4. Using Circular Array
Prevents the need to shift elements.
Wraps around using modulo (%).

5. Using Stack(s)
Two stacks can simulate a queue (interview favorite).

*/

// Underflow Condition (Queue is Empty)
// This happens when you try to dequeue or access the front element from an empty queue.

// Overflow Condition (Queue is Full)
// This occurs when you try to enqueue into a full queue (in fixed-size queues).

/*
How to Handle Them:
-> In Array-Based Queue (non-circular):
Overflow: Happens when rear == size - 1
Underflow: Happens when front > rear or front == -1

-> In Circular Queue:
Overflow: When (rear + 1) % size == front
Underflow: When front == -1 (initially or after last element removed)

-> In Linked List Queue:
Overflow: Rare unless system runs out of memory.
Underflow: When head == NULL
*/




// 1. Using array
#include<iostream>
using namespace std;
const int maxsize=10;  //maximum size of queue
int queue[maxsize];  //defining an array with defined size
int front=-1,rear=-1;  //front and rear are currently -1 as the queue is empty
void enqueue(){
    if(rear==maxsize-1){
        cout<<"Queue Overflow!!\n";
        return;  //exit the function if queue is full
    }
    int n;
    cout<<"Enter element:";
    cin>>n;
    if(front==-1 && rear==-1) front=rear=0; //if queue is empty, set front and rear to 0
    else rear++;

    queue[rear]=n;  //insert element at rear position
    cout<<"Item inserted: "<<n<<endl;  
}

void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue Underflow!!\n";
        return;  //exit the function if queue is empty
    }
    cout<<"Item deleted: "<<queue[front]<<endl;  //display the element being deleted
    if(front==rear) front=rear=0;  //if only one element is present
    else front++;  //deleting from front position

}

void display(){
    cout<<"elements in queue are: ";
    if(front==-1 && rear==-1){
        cout<<"Queue is empty!!\n";
        return;  //exit the function if queue is empty
    }
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
}
int main(){
    cout<<"Enter '1' to enqueue element\nEnter '2' to dequeue element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue();   //to enter an element
                break;
            case 2:
                dequeue();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}






// 2. Using Linked List
#include<iostream>
using namespace std;

struct link{
    int data;
    struct link *next;
};
struct link *front=NULL,*rear=NULL,*node;  //front and rear pointers for the queue
void enqueue(){
    int n;
    cout<<"Enter element:";
    cin>>n;
    node=new link();
    node->data=n;
    node->next=NULL;

    if(front==NULL && rear==NULL) front=rear=node; //if queue is empty, set front and rear to 0
    else {
        rear->next=node; //next of current rear will point to the new node
        rear=node; //linking the new node at the end of queue
    }
    cout<<"Item inserted: "<<node->data<<endl;  
}

void dequeue(){
    if(front==NULL && rear==NULL){
        cout<<"Queue Underflow!!\n";
        return;  //exit the function if queue is empty
    }
    cout<<"Item deleted: "<<front->data<<endl;  //display the element being deleted
    struct link *temp=front;
    front=front->next;
    delete temp;  //free the memory of deleted node

}

void display(){
    cout<<"elements in queue are: ";
    if(front==NULL && rear==NULL){
        cout<<"Queue is empty!!\n";
        return;  //exit the function if queue is empty
    }
    struct link *ptr=front;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    cout<<"Enter '1' to enqueue element\nEnter '2' to dequeue element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue();   //to enter an element
                break;
            case 2:
                dequeue();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}






// Queue Operations :
/* 
| Function    | Description                             |
| ----------- | --------------------------------------- |
| q.push(x) | Add element x at the back (enqueue)   |
| q.pop()   | Remove front element (dequeue)          |
| q.front() | Access the front element                |
| q.back()  | Access the rear (last) element          |
| q.empty() | Check if queue is empty (returns bool)  |
| q.size()  | Returns number of elements in the queue |
*/


// 3.Using Libraries (C++:: STL)
#include<iostream>
#include<queue>
using namespace std;

queue<int> q;

void display(){
    if(q.empty()){
        cout<<"Queue is empty!!\n";
        return;  //exit the function if queue is empty
    }
    cout<<"Elements in queue are: ";
    queue<int> q2=q;  //create a copy of the queue to display elements without modifying the original queue
    while(!q2.empty()){
        cout<<q2.front()<<" ";  //get the front element
        q2.pop();  //remove the front element
    }

}
int main(){
    cout<<"Enter '1' to enqueue element\nEnter '2' to dequeue element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: //to push element
                int n;
                cout<<"Enter element: ";
                cin>>n;
                q.push(n);
                break;
            case 2:  //to delete an element
                if(q.empty()){
                    cout<<"Queue Underflow!!\n";
                    exit(0);  //exit the function if queue is empty
                }
                q.pop();  
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}







// 4. Using Circular Queue
// A circular queue is a linear data structure in which the last position is connected back to the first position to make a circle.
// rear = (rear + 1) % size → so it wraps around to use empty space at the beginning.
// after some operation circular queue looks like :
// Index:        0     1     2     3     4
//              ↓     ↓     ↓     ↓     ↓
// Queue:      60    __    30    40    50
//              ↑                 ↑
//            rear              front


// I. Array 
#include<iostream>
using namespace std;
const int maxsize=5;

int queue[maxsize];  //defining an array with defined size
int front=-1,rear=-1;  //front and rear are currently -1 

void enqueue(){
    int n;
    cout<<"Enter element:";
    cin>>n;
    if((rear+1)%maxsize==front){  //queue is full when rear is one position before front in circular manner (otherwise if there's space ,front will be at different position than rear+1)
        cout<<"Queue Overflow!!\n";
        return;  //exit the function if queue is full
    }
    else if(front==-1 && rear==-1) front=rear=0;
    else rear=(rear+1)%maxsize;  //circular increment of rear[i.e. if rear is at last index, it will point to 0 index next time]

    queue[rear]=n;
    cout<<"Item inserted: "<<n<<endl;  
}

void dequeue(){
    if(front==-1 && rear==-1){
        cout<<"Queue Underflow!!\n";
        return;  //exit the function if queue is empty
    }
    cout<<"Item deleted: "<<queue[front]<<endl;  //display the element being deleted
    if(front==rear) front =rear=0; //if only one element is present
    else front=(front+1)%maxsize;  //circular increment of front[i.e. if front is at last index, it will point to 0 index next time]


}

void display(){
    cout<<"elements in queue are: ";
    if(front==-1 && rear==-1){
        cout<<"Queue is empty!!\n";
        return;  //exit the function if queue is empty
    }
    int i=front;
    while(i!=rear+1){ // loop until we reach the position after rear(because we need to print rear also)
        cout<<queue[i]<<" ";
        i=(i+1)%maxsize;
    }
}
int main(){
    cout<<"Enter '1' to enqueue element\nEnter '2' to dequeue element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue();   //to enter an element
                break;
            case 2:
                dequeue();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}





//II. Linked List
#include<iostream>
using namespace std;

struct link{
    int data;
    struct link *next;
};
struct link *front=NULL,*rear=NULL,*node;  //front and rear pointers for the queue
void enqueue(){
    int n;
    cout<<"Enter element:";
    cin>>n;
    node=new link();
    node->data=n;
    node->next=NULL;

    if(front==NULL && rear==NULL){
        front=rear=node; //if queue is empty, set front and rear to 0
        rear->next=front;
    }

    else {
        rear->next=node; //next of current rear will point to the new node
        node->next=front; //new node will point to front
        rear=node; //modify the rear pointer to point to the new node
    }
    cout<<"Item inserted: "<<node->data<<endl;  
}

void dequeue(){
    if(front==NULL && rear==NULL){
        cout<<"Queue empty!!\n";
        return;  //exit the function if queue is empty
    }

    cout<<"Item deleted: "<<front->data<<endl;  //display the element being deleted
    struct link *temp;

    if(front==rear){
        temp=front;
        front=rear=NULL;  //front and rear will be NULL
        delete temp;
    }
    else{
        temp=front;
        front=front->next;  //front will point to next node
        rear->next=front; //rear will point to new front as it is circular queue
        delete temp;  //free the memory of deleted node
    }

}

void display(){
    if(front==NULL && rear==NULL){
        cout<<"Queue is empty!!\n";
        return;  //exit the function if queue is empty
    }
    cout<<"elements in queue are: ";
    struct link *ptr=front;
    while(ptr->next!=front){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data<<" "; //to print the last element which points to front
}
int main(){
    cout<<"Enter '1' to enqueue element\nEnter '2' to dequeue element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                enqueue();   //to enter an element
                break;
            case 2:
                dequeue();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}








// 5. Using Two Stacks (to simulate a queue)
// stack1: For enqueue (push)
// stack2: For dequeue (pop)

// Approach:
// Enqueue (push): Just push into stack1
// Dequeue (pop):
// If stack2 is empty:
// Pop all elements from stack1 and push into stack2
// Pop from stack2

#include<iostream>
#include<stack>
using namespace std;

class QueueUsingStack {
    stack<int> s1,s2;
    public:
    void enqueue(int x){
        s1.push(x);  //push the element onto stack1
        cout << "Enqueued: " << x << endl;
    }
    int dequeue(){
        if(s2.empty()){
            if(s1.empty()){
                cout<<"queue is empty!!\n";
                return -1;
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();   //top element that is going to be deleted
        s2.pop();  //to delete element from s2;
        return val;
    }
    int front(){
        if(s2.empty()){
            if(s1.empty()){
                cout<<"Queue is empty!!";
                return -1;
            }
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    void display(){
        if(s2.empty() && s2.empty()){
            cout<<"Queue is empty!!";
            return ;
        }  
        stack<int> temp1=s1;
        stack<int> temp2=s2; 
        cout<<"Elements are: ";
        //printing s2
        // s2 holds the correct queue order, but only for the elements that have been moved to it via dequeue/front.
        while(!temp2.empty()){  //temp 2 store s2 (which contain the elements in correct order)
            cout<<temp2.top()<<" ";
            temp2.pop();
        }
        //printing reversed s1
        //for Recently enqueued elements
        stack<int > temp3;   //temp 3 store reversed s1
        while(!temp1.empty()){
            temp3.push(temp1.top());
            temp1.pop();
        }

        while(!temp3.empty()){
            cout<<temp3.top()<<" ";
            temp3.pop();
        }

    }
};

int main(){
    QueueUsingStack q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.front() << endl; // 10
    cout<<"Dequeue: "<<q.dequeue()<<endl;  //will delete front element i.e. 10
    cout << "Front element after dequeue: " << q.front() << endl; //20

    q.enqueue(40);
    cout << "Front element after enqueue: " << q.front() << endl; //20
    q.display();     // 20 30 40

    cout<<"Dequeue: "<<q.dequeue()<<endl;  //will delete front element i.e. 20
    cout<<"Dequeue: "<<q.dequeue()<<endl;  //will delete front element i.e. 30
    cout<<"Front element after dequeues: " <<  q.front() << endl;  //40
    q.enqueue(50);
    q.enqueue(60);
    q.display();    //40 50 60
}








