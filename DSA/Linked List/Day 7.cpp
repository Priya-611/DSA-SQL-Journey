// 2. Add Two Numbers
// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

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
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long n1=0,n2=0,m=1;
        //storing value of l1 in number format
        while(l1){
            n1+= l1->val *m;
            m*=10;
            l1=l1->next;
        }
        m=1;

        //storing value of l2 in number format
        while(l2){
            n2+= l2->val *m;
            m*=10;
            l2=l2->next;
        }

        //adding both the numbers and storing each digit in reverse order
        long long t=n1+n2;
        ListNode* ptr=new ListNode();
        ListNode* curr=ptr;
        if(t==0){
            return ptr;
        }
        //storing from last digit
        while(t>0){
            curr->next=new ListNode(t%10);
            t/=10;
            curr=curr->next;
        }
        return ptr->next;
    }
};*/
//this doesn't work if linked list has many digits
//optimal solution

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr=new ListNode();  //initially ptr has 0
        ListNode* curr=ptr;  //for building result
        int carry=0;
        while(l1 || l2 || carry){  //if any of this contain value
            int n1 = l1 ? l1->val : 0;  //if l1!=NULL store val of l1 in n1 else store 0
            int n2 = l2 ? l2->val : 0;  //if l2!=NULL store val of l2 in n2 else store 0
            int sum=n1+n2+carry;  
            carry=sum/10; //store carry part here so that it can be added in next turn
            curr->next=new ListNode(sum%10);   //create node with remainder i.e. next of current points at this digit
            curr=curr->next;  //move current 

            //if l1 or l2 any contain value move to next node
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        
        return ptr->next; // return actual result (skip first part i.e. 0) 
    }
};







// 160. Intersection of Two Linked Lists
// Approach:
// List A:        a1 → a2 → c1 → c2 → c3  
// List B:   b1 → b2 → b3 → c1 → c2 → c3  

// Pointer A path: a1 → a2 → c1 → c2 → c3 → NULL → b1 → b2 → b3 → c1
// Pointer B path: b1 → b2 → b3 → c1 → c2 → c3 → NULL → a1 → a2 → c1
//                                                                ↑ Both meet here

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA;
        ListNode *l2=headB;

      //till both the pointers re equal 
        while(l1!=l2){
          //if l1 has reached NULL(end of the LL)
          //set it to another node (headB)
            if(l1==NULL) l1=headB;
            else l1=l1->next;  //otherwise move to next node
          //if l2 has reached NULL(end of the LL)
          //set it to another node (headA)
            if(l2==NULL) l2=headA;
            else l2=l2->next;  //otherwise move to next node

          //in this way if length of one LL is shorter than another both will travel equal dist and reach intersection in next traversal
        }
        return l1;
    }
};







// 61. Rotate List
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp=head;
        int c=0;  //to find length of LL
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        k=k%c;   //to avoid unneccessary rotation
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(k>0){
            ListNode *ptr=head;
            while(ptr->next->next!=NULL ){
                ptr=ptr->next;
            }
            
            ListNode* curr=ptr->next; //current is the last node
            ptr->next=NULL;
            curr->next=head;
            head=curr;
            
            k--; 
        }
        return head;
    }
};








// 143. Reorder List
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

// approach :
// Step 1: find mid of the LL using Floyd' Cycle Detection
// Step 2: reverse the second half and cut off the first half
// Step 3: merge the Values of bth LL alternatively
  
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
    void reorderList(ListNode* head) {
        //1. find mid
        ListNode* fast=head;
        ListNode* slow= head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        //2. reverse the second half
        ListNode *ptr=slow->next;
        ListNode *temp=NULL;
        while(ptr!=NULL){
            ListNode* curr=ptr->next;
            ptr->next=temp;
            temp=ptr;
            ptr=curr;
        }
        //temp is the new head of 2nd half

        slow->next=NULL;  //cut off the first half

        //3. merge both LL alternatively
        ListNode *f=head;
        ListNode *s=temp;
        while(f!=NULL && s!=NULL){
            ListNode *t1=f->next;  //store next of f (first LL)
            ListNode *t2=s->next;  //store next of s (second LL)
            // [f --> s --> t1 --> t2 --> ....]
            f->next=s;  
            s->next=t1;  //next of second  points to 2nd node of first LL

          //increment to next node;
            f=t1;
            s=t2;


        }

    }
};






// 142. Linked List Cycle II
//aproach: using Floyd's Cycle Detection (tortoise and Hare)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* fast=head;
        ListNode*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;

            //firstly we'll get the intersection point
            if(fast==slow) {
                slow=head;  //now we'll start slow from head again
                while(fast!=slow){ //now until they aren't equal keep traversing as to find the start of cycle
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow; //start of cycle
            }
            
        }
        return NULL;
    }
};






// 148. Sort List
// keep dividing and then merge
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        //find mid of LL
        ListNode* fast=head->next;
        ListNode *slow=head;
        
        while(fast!=NULL &&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *temp=slow->next;  //temp point to start of second half 
        slow->next=NULL; //make slow of next NULL (cut off first half)
        //recursively divide the LL
      
        ListNode *l1= sortList(head); // a new LL to sort the first half
        ListNode *l2= sortList(temp); // a new LL to sort the second half
        return merge(l1,l2);   //merge both the lists
        
    }
    ListNode* merge(ListNode* l1 , ListNode *l2){
        ListNode *ptr= new ListNode();
        ListNode *curr= ptr;   //curr moves and ptr remains as head 
      
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                curr->next =l1;
                l1=l1->next;
            }
            else{
                curr->next= l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
      
      //if any of the list has elements 
        if(l1){
            curr->next=l1;         
        }
        if(l2){
            curr->next=l2;
        }
        return ptr->next;
    }
};

