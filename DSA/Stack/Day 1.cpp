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


// Do not confuse between a user-defined stack and stack in memory
/*
1. Call Stack (Memory Stack / System Stack) ->  part of computer memory used by the CPU to manage function calls, local variables, and return addresses during program execution.
    -> Managed by the compiler(runtime). / Each function call gets a stack frame. / When a function is called, a new frame is pushed onto the call stack.
    -> When a function returns, the frame is popped off the stack. / Stored in RAM, grows/shrinks automatically as functions are called and return.
    -> It's limited in size (can cause stack overflow if you use too much, e.g., deep recursion).

2. Stack Data Structure (User-defined Stack) -> This is the data structure you define in your program using: Array, Linked list, STL (stack<int>, etc.)
    -> Follows LIFO: Last In, First Out.
    -> You manually define and control it.
    -> Used for problems like: Expression evaluation (e.g., postfix), Undo operations, Balancing parentheses, DFS traversal 
*/



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






// Operations in vector
/*
| **Operation**         | **Description**                                                              |
| --------------------- | ---------------------------------------------------------------------------- |
| `push_back(x)`        | Adds element `x` to the end of the vector.                                   |
| `pop_back()`          | Removes the last element.                                                    |
| `insert(pos, val)`    | Inserts `val` at the position `pos` (iterator).                              |
| `erase(pos)`          | Removes the element at the given position (iterator).                        |
| `clear()`             | Removes all elements from the vector.                                        |
| `size()`              | Returns the number of elements in the vector.                                |
| `capacity()`          | Returns the current capacity (allocated memory size).                        |
| `resize(n)`           | Resizes the vector to `n` elements. New elements initialized with default.   |
| `reserve(n)`          | Reserves memory for at least `n` elements (to avoid frequent reallocations). |
| `empty()`             | Returns `true` if the vector is empty.                                       |
| `at(index)`           | Returns reference to element at `index` (with bounds checking).              |
| `front()`             | Returns the first element.                                                   |
| `back()`              | Returns the last element.                                                    |
| `begin()` / `end()`   | Returns iterator to the first/last+1 element.                                |
| `rbegin()` / `rend()` | Returns reverse iterator to last/first–1 element.                            |
| `assign(n, val)`      | Fills vector with `n` copies of `val`.                                       |
| `swap(v2)`            | Swaps contents with another vector `v2`.                                     |
| `emplace(pos, val)`   | Constructs element `val` in-place at `pos` (faster than insert).             |
| `emplace_back(val)`   | Constructs element at the end (faster than push\_back).                      |
*/


// Stack using vector
#include<iostream>
#include<vector>
using namespace std;
 
class Stack{
    vector<int> v;
    public:
    void push(){
        int n;
        cout<<"Enter element: ";
        cin>>n;
        cout<<"Element inserted: "<<n<<endl;
        v.push_back(n);
    }

    void pop(){
        if(v.empty()){
            cout<<"Underflow"<<endl;
            exit(0);
        }
        cout<<"Element deleted: "<<v.back()<<endl;
        v.pop_back();
    }

    int top(){
        if(v.empty()){
            cout<<"stack is empty\n";
            return -1;
        }
        return v.back();
    }

    bool isEmpty(){
        return v.empty();
    }

    void display(){
        if(v.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Elements are: ";
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
    }
};
int main(){
    Stack s;
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '4' to see the topmost element\nEnter '5' to see if vector is empty or not\nEnter '-1' to exit\n";
    int choice;

    while(true){
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:   //insertion
                s.push();
                break;
            case 2:  //deletion
                s.pop();
                break;
            case 3:  
                s.display();
                break;
            case 4: 
                cout<<"Top element : "<<s.top(); //to see the topmost element
                break;
             case 5:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case -1:
                exit(0);
            default:
                cout<<"Enter correct choice: ";    
        }
    }
}





//Template: allows you to write generic code — meaning, you can create a function or class that works with any data type (int, float, string, custom class, etc.) without rewriting the code for each type.
/*
template<typename T>
class Stack {
    // works with T = int, float, string, etc.
};
*/

#include<iostream>
#include<vector>
using namespace std;
 
template<typename T>
class Stack{
    vector<T> v;

    public:
    void push(T val){
        cout<<"Element inserted: "<<val<<endl;
        v.push_back(val);
    }

    void pop(){
        if(v.empty()){
            cout<<"Underflow\n"<<endl;
            return;
        }
        cout<<"Element deleted: "<<v.back()<<endl;
        v.pop_back();
    }

    T top(){
        if(v.empty()){
            cout<<"stack is empty\n";
            return T(); // default value (0 for int, "" for string, etc.)
        }
        return v.back();
    }

    bool isEmpty(){
        return v.empty();
    }

    void display(){
        if(v.empty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Elements are: ";
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack<int> s;
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '4' to see the topmost element\nEnter '5' to see if vector is empty or not\nEnter '-1' to exit\n";
    int choice;

    while(true){
        cout<<"\nEnter choice: ";
        cin>>choice;
        switch(choice){
            case 1:   //insertion
                int n;
                cout<<"Enter element: ";
                cin>>n;
                s.push(n);
                break;
            case 2:  //deletion
                s.pop();
                break;
            case 3:  
                s.display();
                break;
            case 4: 
                cout<<"Top element : "<<s.top()<<endl; //to see the topmost element
                break;
             case 5:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case -1:
                exit(0);
            default:
                cout<<"Enter correct choice: ";    
        }
    }
}
// for string
/*
int main(){
    Stack<string> s;
    cout<<"Enter '1' to push element\nEnter '2' to pop element\nEnter '3' to display all elements\nEnter '4' to see the topmost element\nEnter '5' to see if vector is empty or not\nEnter '-1' to exit\n";
    int choice;
    cin.ignore();     // Clear input buffer
    while(true){
        cout<<"\nEnter choice: ";
        cin>>choice;
        cin.ignore();   // Clear newline left after int input
        switch(choice){
            case 1: {  //insertion
                string n;
                cout<<"Enter element: ";
                getline(cin, n);  //for input string
                s.push(n);
                break;
            }
        }
    }
}

*/

//or
/*
int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.display();
    s1.pop();

    Stack<string> s2;
    s2.push("Hello");
    s2.push("World");
    s2.display();
    cout << "Top: " << s2.top() << endl;

    return 0;
}
*/



