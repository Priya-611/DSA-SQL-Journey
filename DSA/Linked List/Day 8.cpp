
// 328. Odd Even Linked List
// (all odd index values ,then all even index values)
//Approach:
// 1. odd pointer will start from head and even pointer start from next of head
// 2. next of odd will point to next of even (i.e. skipping one node) and move to it's next 
// 3. next of even points to next of odd (i.e. skipping one node) and moves to it's next
// 4. at last odd of next points to start of even pointers head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* odd=head;  //start from 1st position
        ListNode *even=head->next;   //start from 2nd position
        ListNode *evenHead=even;

        while(even!=NULL && even->next!=NULL){
            odd->next=even->next;  //odd of next points to even -> next(which is odd position)
            odd=odd->next;  //now odd moves to it's next (skipping one node)

            even->next= odd->next;  //next of even points to odd->next(which is even position)
            even=even->next;  //now even moves to it's next( skipping one node)
        }  
        odd->next=evenHead;  // attach even list after odd list
        return head;
    }
};




// STL( Standard Template Library (STL))
// Doubly LL 
/*
std::list is a container provided by the Standard Template Library (STL).
-> std::list in C++ is a doubly linked list, not singly.
-> It is a sequence container that allows constant time insert and erase operations anywhere within the sequence, and iteration in both directions.
Internally, it is implemented as a doubly-linked list.


1. Creation: 
std::list<int> l1;                  // Empty list
std::list<int> l2 = {10, 20, 30};   // Initialize with values


2. Insertion:
l.push_front(5);       //Add at front
l.push_back(40);       // Add at back
auto it = l.begin(); advance(it, 2); l.insert(it, 25);     //Insert at pos


3. Deletion:
l.pop_front();          //Remove from front
l.pop_back();           //Remove from back
auto it = l.begin(); advance(it, 1); l.erase(it);       //Erase at pos
l.remove(30);           //remove all of value x


4. Traversal:
using for loop
using for each loop 


5. Size and Capacity:
l.size();       // Number of elements
l.empty();      // true if list is empty


6. Sorting and Reversing:
l.sort();       // Sort in ascending order
l.reverse();    // Reverse the list


7. Merging Lists:
l1.merge(l2);       // l2 becomes empty, and its elements move to l1


8. Unique Elements:
l.unique(); // Removes consecutive duplicates => {1, 2, 3, 4}


9. Clear Entire List:
l.clear();
*/

// auto = automatic type deduction
// advance(iterator,no. of steps )        //standard library function that moves an iterator forward (or backward).

#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l;
    //insertion
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    //10->20->30
    l.push_front(40);
    //40->10->20->30

    //1st way of traversal
    for(int x: l) cout<<x<<" ";   //40 10 20 30 
    cout<<endl;

    //deletion
    l.pop_back();   //40 10 20
    l.pop_front();  //10 20

    insertion
    auto it =l.begin();
    advance(it,1);      // move iterator to 1st position after l.begin()
    l.insert(it,15);    // insert 15 at that position

    //2nd way of traversal
    for(auto it = l.begin(); it != l.end(); ++it)
    cout << *it << " ";  //value at 'it' pointer
    // 10 15 20     
}




//Circular LL
#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> cll={1,2,3,4,5,6};
    auto it=cll.begin();
    
    int loopCount=12;   // Number of elements to print (e.g. 2 full rounds)
    while(loopCount--){
        cout<<*it<<" ";    //1 2 3 4 5 6 1 2 3 4 5 6
        ++it;
        if(it==cll.end()){
            it=cll.begin();   // loop back to start
        }
    }
}




//Singly LL
/*
std::forward_list
->This is a singly linked list introduced in C++11.
-> It is faster and uses less memory than std::list because it only stores one pointer (next) instead of two (next and prev).
*/

#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> sll={11,22,33,44};
    sll.push_front(55);   //only insertion at beginning as for adding at the end you need to perform traversal

    sll.pop_front();      //delete from only beginning is possible

    for(int v: sll) cout<<v<<" ";   //11 22 33 44
}

