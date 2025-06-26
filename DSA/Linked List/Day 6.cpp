
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
        ListNode *list3=NULL;   //for a new list
        ListNode *current=NULL;  //current will be pointing to currently caccessed node

        while(list1!=NULL && list2!=NULL){  //when both of them contain data
            ListNode *node=new ListNode ();
          //whichevere list has small data fill that in new list3
            if(list1->val < list2->val){
                node->val = list1->val;
                list1=list1->next;
            }
            else {
                node->val=list2->val;
                list2=list2->next;
            }
            node->next=NULL;
          //setting value of list3 and current
            if(list3==NULL){
                list3=node;
                current=node;
            }
            else{
                current->next=node;
                current=node;

            }
        }
      //if list1 is still having data
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
      //if list 2 still have data
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


