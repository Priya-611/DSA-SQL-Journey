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

#include<iostream>
#include<deque>
using namespace std;

deque<int> dq;

void display(){
    if(dq.empty()){
        cout<<"Dequeue is empty!!\n";
        return;  
    }
    
    deque<int>::iterator it;  //using iterator to traverse the deque
    cout<<"Elements in dequeue are: ";
    for(it=dq.begin(); it!=dq.end(); it++){
        cout<<*it<<" ";  //display the elements in dequeue
    }
}

int main(){
    cout<<"Enter '1' to enqueue in front\nEnter '2' to enqueue in back(rear)\nEnter '3' to dequeue from front\nEnter '4' to dequeue from back\nEnter '5' to display\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        int n;
        switch(choice){
            case 1: 
                cout<<"Enter element: ";
                cin>>n;
                dq.push_front(n);   //to enter an element at front
                break;
            case 2:
                cout<<"Enter element: ";
                cin>>n;
                dq.push_back(n);   //to enter an element at back
                break;
            case 3:
                cout<<"Item deleted: "<<dq.front()<<endl;
                dq.pop_front();   //to delete an element from front
                break;
            case 4:
                cout<<"Item deleted: "<<dq.back()<<endl;
                dq.pop_back();   //to delete an element from back   
                break;
            case 5:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice\n";

        }
    }  
}







// Stack Using Queues

// A stack is LIFO (Last In First Out), but a queue is FIFO (First In First Out).
// So we need to simulate LIFO behavior using FIFO structure(s).
/*
Two Common Approaches:
1. Using two queues
Costly push() — rearranges elements to maintain stack order
pop() is O(1)

2. Using one queue
Slightly tricky but more efficient
*/



// 1. Using two queues

// Two queues: q1 and q2
// The goal is to simulate LIFO (stack behavior) using FIFO (queue behavior)
/*
push(x): Push into q2 | Move all elements from q1 → q2 |Swap q1 and q2 | So the new element is always at the front of q1 (top of stack)
pop(): Just q1.pop() (always front of q1)
top(): Just q1.front()
*/

// We add the new element into q2
// Then push all existing elements from q1 into q2
// so that the new element in q2 is at the front and then pushing elements from q1 they are pushed to the back of q2[i.e. q2 has elements in reverse order]
// Then we swap q1 and q2 now q1 holds the current order and q2 is empty]
// So the new element always comes first in the new queue (q1)
// Hence, q1.front() always gives us the stack top

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1,q2;
    public:
    void push(int x){
        q2.push(x);  //push the element onto the queue
        cout << "Pushed: " << x << endl;
    
        while(!q1.empty()){  //reversing queue
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);

    }
    void pop(){
        if(q1.empty()){
            cout<< "Stack is empty!!\n";
            return;
        }
        cout<<"Popped: " << q1.front() << endl;  //display the top element that is going to be deleted
        q1.pop();  //pop the top element
    }

    int top(){
        if(q1.empty()){
            cout << "Stack is empty!!\n";
            return -1;  //return -1 if stack is empty
        }
        return q1.front();  //return the top element

    }

    bool isEmpty(){
        return q1.empty();
    }

    void display(){
        if(q1.empty()){
            cout<<"Stack is empty!!\n";
            return;
        }
        cout<<"Elements in stack are: ";
        queue<int> temp = q1;  //create a temporary queue to display elements
        while(!temp.empty()){
            cout << temp.front() << " ";  //display the elements in stack
            temp.pop();
        }   
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // 30

    s.pop();  // will delete top element i.e. 30

    s.display(); // 20 10

    s.push(40);
    s.display(); // 40 20 10

    return 0;

}





// 2. Using one queue

// we'll push elements into the queue and then rotate the queue to maintain stack order.
// means whenever we push an element, we'll loop through the queue and push each element from the front to the back, except the last element
// so each element from front goes to the last [so that the last pushed element is at the front].
// i.e.  the top of the stack will always be at the front of the queue.
// so while popping, the front element will be the deleted.[as queue pops front __cpp_lib_incomplete_container_elements]

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q;
    public:
    void push(int x){
        q.push(x);  //push the element onto the queue
        int size = q.size();
        for(int i=0;i<size-1;i++){  //reversing queue
            q.push(q.front());  //pushing each element front front to back of the queue ,, such that while deleting, the last pushed element will be at the front
            q.pop();
        }

    }
    void pop(){
        if(q.empty()){
            cout<< "Stack is empty!!\n";
            return;
        }
        cout<<"Ppopped: " << q.front() << endl;  //display the top element that is going to be deleted
        q.pop();  //pop the top element
    }

    int top(){
        if(q.empty()){
            cout << "Stack is empty!!\n";
            return -1;  //return -1 if stack is empty
        }
        return q.front();  //return the top element

    }

    bool isEmpty(){
        return q.empty();
    }

    void display(){
        if(q.empty()){
            cout<<"Stack is empty!!\n";
            return;
        }
        cout<<"Elements in stack are: ";
        queue<int> temp = q;  //create a temporary queue to display elements
        while(!temp.empty()){
            cout << temp.front() << " ";  //display the elements in stack
            temp.pop();
        }   
    }

};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // 30

    s.pop();  // will delete top element i.e. 30

    s.display(); // 20 10

    s.push(40);
    s.display(); // 40 20 10

    return 0;

}






//Q) Reversing queue elements using Stack 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> s;

    //push all elements of queue[from front] into stack
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    //push stack elements back into queue i.e. now queue will have elements in reverse order
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void printQueue(queue<int> q){
    if(q.empty()){
        cout<<"Queue is empty!!\n";
        return;
    }
    queue<int> temp=q; // create a copy of the queue to display elements without modifying the original queue
    while(!temp.empty()){
        cout<<temp.front()<<" "; // get the front element
        temp.pop(); // remove the front element
    }
    cout << endl;
}


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << "Front element: " << q.front() << endl; // 10

    cout<<"Original Queue: ";
    printQueue(q); // 10 20 30 40 50

    reverseQueue(q); 

    cout<<"Reversed Queue: ";
    printQueue(q); // 50 40 30 20 10
    
    cout << "Front element: " << q.front() << endl; // 50
    return 0;

}





// Q) Reversing Queue usning recursion
/*
| Step      | temp has      | queue has  |
| --------- | ------------- | ---------- |
| 1st call  | 10            | 20 30 40 50|
| 2nd call  | 20            | 30 40 50   |
| 3rd call  | 30            | 40 50      |
| 4th call  | 40            | 50         |
| Last call | 50            | empty      |

now when empty queue is passed to the function, it will return 
and go back to the previous call where 50 was stored in temp
it will read the last line of the function and push 50 back into the queue
then it will return to the previous call where 40 was stored in temp and push 40 back into the queue
and so on
and then the elements will be pushed back in reverse order
*/

#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    if(q.empty()) return; // base case

    //remove front element
    int temp=q.front();
    q.pop();

    // recursive call
    reverseQueue(q); 

    // push the front element to the back of the queue
    q.push(temp); 
}

void printQueue(queue<int> q){
    if(q.empty()){
        cout<<"Queue is empty!!\n";
        return;
    }
    queue<int> temp=q; // create a copy of the queue to display elements without modifying the original queue
    while(!temp.empty()){
        cout<<temp.front()<<" "; // get the front element
        temp.pop(); // remove the front element
    }
    cout << endl;
}


int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout << "Front element: " << q.front() << endl; // 10

    cout<<"Original Queue: ";
    printQueue(q); // 10 20 30 40 50

    reverseQueue(q); 

    cout<<"Reversed Queue: ";
    printQueue(q); // 50 40 30 20 10
    
    cout << "Front element: " << q.front() << endl; // 50
    return 0;

}


