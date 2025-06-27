
// 206. Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr=head;   //ptr pointing to head
        ListNode *temp=NULL;   //temp will be pointing to NULL

        while(ptr!=NULL){   //till ptr is not null
            ListNode *current = ptr->next;    // current will point to the next of ptr each time
            ptr->next=temp;  //next of ptr will point to temp
            temp=ptr;  //temp will now point to ptr
            ptr=current;   //ptr will now point to current 
        }
        return temp;
    }
};







// 21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3=NULL;
        ListNode *current=NULL;

        while(list1!=NULL && list2!=NULL){
            ListNode *node=new ListNode ();
            if(list1->val < list2->val){
                node->val = list1->val;
                list1=list1->next;
            }
            else {
                node->val=list2->val;
                list2=list2->next;
            }
            node->next=NULL;
            if(list3==NULL){
                list3=node;
                current=node;
            }
            else{
                current->next=node;
                current=node;

            }
        }
        while(list1 !=NULL){
            ListNode *node=new ListNode ();
            node->val=list1->val;
            node->next=NULL;
            if(list3==NULL){
                list3=node;
                current=node;
            }
            else{
                current->next=node;
                current=node;
            }
            
            list1=list1->next;

        }
        while(list2 !=NULL){
            ListNode *node=new ListNode ();
            node->val=list2->val;
            node->next=NULL;
            if(list3==NULL){
                list3=node;
                current=node;
            }
            else{
                current->next=node;
                current=node;
            }
            
            list2=list2->next;

        }
        return list3;
    }
};






// 876. Middle of the Linked List
//if two middle node return second one 
// Tortoise and Hare Algorithm (Two-Pointer Technique)
// slow moves one step at a time.
// fast moves two steps at a time.
// When fast reaches the end (or loops back to start in circular lists), slow will be at the middle.
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};





// 237. Delete Node in a Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};*/

// optimal solution
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;  // Store the next node (which will be deleted)
        //modifying current node by changing it value and storing next node's value 
        //and deleting the next node
        node->val=node->next->val;  //Copy the data from the next node into the current node
        node->next=temp->next;  // Skip over the next node
        delete temp;  //deleting temp (i.e. the next node )
    }
};






// 19. Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr=head;
        int c=0;
        //find the length of LL
        while(ptr!=NULL){
            c++;
            ptr=ptr->next;
        }
        //if length of LL and node to be deleted are same (that means you are deleting the head node
        if((c==1 && n==1)   || c==n){
            head=head->next;
            return head;
        }
        //else wise
        int j=c-n;   //find the no. of nodes to be skipped from the start
        int i=1;
        ListNode *curr=head;
        while(i<j){  //till i < j (keep traversing to reach the node to be deleted)
            curr=curr->next;
            i++;
        }
        // delete node by pointing the previous node's next to next node
        curr->next=curr->next->next;
    
        return head;
    }
};






// 234. Palindrome Linked List
//approach:
// i) find mid and divide the LL in two parts
// ii) reverse the second half of LL
// ii) now compare values both the LL


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
    bool isPalindrome(ListNode* head) {

        //finding mid
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        //reversing the second half
        ListNode* temp=NULL;
        ListNode* ptr=slow->next;
        while(ptr!=NULL){
            ListNode *nextNode=ptr->next;
            ptr->next=temp;
            temp=ptr;
            ptr=nextNode;
        }
        //temp is the head of reversed LL

        //comparing values of both LL
        ListNode* first=head;
        ListNode* second=temp;
        while(first!=NULL && second!=NULL){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }

};





// 83. Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr=head;
        while(ptr!=NULL && ptr->next!=NULL){
            //if ptr's data and ptr's next's data are same, we'll skip next value and directly go to next's next
            if(ptr->val==ptr->next->val){
                
                ptr->next=ptr->next->next;

            }
            else{
                ptr=ptr->next;
            }
        }
        return head;
    }
};





// 141. Linked List Cycle
// Using Floyd’s Cycle Detection Algorithm (Tortoise and Hare) 
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
    bool hasCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            //if fast == slow within the loop then LL has cycle
            if(fast==slow) return true;
        }
        return false;
    }
};



