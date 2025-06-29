// Stack: a linear data structure that follows the LIFO (Last In, First Out) principle.

/*
LIFO (Last In, First Out) means the last element added (pushed) to the stack is the first one removed (popped).
-> You can only take the top plate off.
-> You add (push) or remove (pop) only from the top.


Operation:
push(x)     	Add x to the top of the stack
pop()	        Remove the top element
top() / peek()	View the top element without removing it
isEmpty()	    Check if the stack is empty
size()	        Returns the number of elements in the stack



Ways to Implement a Stack:
1. Using Arrays
-> Manual implementation with a fixed-size array.
-> Keeps a variable (top) to track the current top element.
-> Simple but limited in size (stack overflow if full).

2. Using C++ STL (std::stack)
-> Quickest and easiest way.
-> Provided by the C++ Standard Template Library (STL).
-> Internally uses a deque (double-ended queue).
-> Ideal for competitive programming or projects where time is limited.

3. Using Linked List
-> Dynamic memory allocation.
-> No size limitation (until system memory runs out).
-> Each new element becomes the new top by adding a new node.
*/

// Stack overflow occurs when you try to push an element into a stack that is already full.
// Stack underflow occurs when you try to pop an element from an empty stack.





// 1. Using Array:
#include<iostream>
using namespace std;

const int maxsize=10;
int stack[maxsize];  //defining an array with defined size
int top=-1;  //top is currently -1 as the stack is empty

void push(){
    if(top==maxsize){
        cout<<"Stack Overflow!!";
        exit(0);
    }
    cout<<"Enter element: ";
    int n;
    cin>>n;
    top++;   //before inserting into stack array increase top 
    stack[top]=n;
    cout<<"Item inserted: "<<n<<endl;

}
void pop(){
    if(top==-1){
        cout<<"Stack Underflow!!";
        exit(0);
    }
    cout<<"Item deleted: "<<stack[top]<<endl;
    top--; //decrease top by 1 position 

}
void display(){
    if(top==-1){
        cout<<"Stack is empty!!";
        exit(0);
    }
    cout<<"Elements are: ";
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";  //elements from the top of stack
    }
}

int main(){
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                push();   //to enter an element
                break;
            case 2:
                pop();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"Enter correct choice: ";

        }
    }  
}





// 2. Using C++ STL (std::stack)
#include<iostream>
#include<stack>
using namespace std;

stack<int> s1; //create an stack with integer elements

void display(){
    if(s1.empty()){
        cout<<"Stack is empty";
        exit(0);
    }
    stack<int>s2=s1;  //copying so element won't get deleted while poping from original stack
    cout<<"Elements are: ";
    while(!s2.empty()){   //till s2 is not empty keep displaying
        cout<<s2.top()<<" ";
        s2.pop();
    }
}

int main(){
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    int n;
    while(true){
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:   //insertion
                cout<<"Enter element: ";
                cin>>n;
                cout<<"Element inserted: "<<n<<endl;
                s1.push(n);
                break;
            case 2:  //deletion
                if(s1.empty()){
                    cout<<"Underflow"<<endl;
                    exit(0);
                }
                else {
                    cout<<"Element deleted: "<<s1.top();
                    s1.pop();
                }
                break;
            case 3:  
                display();
                break;
            case -1:
                exit(0);
            default:
                cout<<"Enter correct choice: ";    
        }
    }
}







// 3. Using Linked List
#include<iostream>
using namespace std;
struct link{
    int data;
    struct link *next;
};
struct link *top=NULL, *node;
void push(){
    cout<<"Enter element: ";
    int val;
    cin>>val;
    node=new link();
    node->data=val;
    node->next=top;  //next of node will point to top which is the address of previous node
    top=node;  //modify top 
    cout<<"Item inserted: "<<val<<endl;

}

void pop(){
    if(top==NULL){
        cout<<"Stack Underflow";
        exit(0);
    }
    link *temp=top;  //store topmost element to be deleted 
    top=top->next; //move top pointer to it's next node
    cout<<"Item deleted: "<<temp->data;
    delete temp;  //free the memory

}

void display(){
    if(top==NULL){
        cout<<"Stack is empty";
        exit(0);
    }
    link *ptr=top;
    cout<<"Elemets are: ";
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main(){
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '-1' to exit\n";
    int choice;
    while(true){
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
                push();   //to enter an element
                break;
            case 2:
                pop();   //to delete an element
                break;
            case 3:
                display();   //to display the elements in stack
                break;
            case -1:
                exit(0);   //for exiting the program
            default:
                cout<<"\nEnter correct choice: ";

        }
    }  
}


