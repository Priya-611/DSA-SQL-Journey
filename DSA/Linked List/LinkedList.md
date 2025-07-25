## Linked List:

### Day 1: Basics of Singly Linked List (SLL)
  * Introduction to Linked List: structure, advantages over arrays.
  * Types: Singly, Doubly, Circular.
  * `struct` and pointer-based dynamic memory management.
  * Creating a singly linked list.
  * Displaying elements.
  * Finding the largest element.
  * Summing all elements.
  * Sorting elements.
  * Creating multiple linked lists (2 and 5 lists).
  * Printing a list in reverse (through logic).


### Day 2: Insertion, Deletion & Merge in SLL
  * Dynamic creation (with `-1` as stop signal).
  * Inserting at any position.
  * Deleting from a given position or a given value.
  * Merging two sorted lists into a new list.
  * "Skip Y delete X" pattern logic.
  * Difference between position-based and value-based deletion.
  * Traversal logic and pointer adjustment.
  * Using multiple pointers for safe manipulation.
  * Edge case handling in insert/delete.


### Day 3: Doubly Linked List (DLL)
  * Introduction to DLL: bidirectional traversal using `prev` and `next`.
  * Creating, displaying forward and backward.
  * Insertion at any position.
  * Deletion by position and by value.
  * Finding length of DLL.
  * Carefully managing both `prev` and `next` pointers.
  * Boundary conditions like deletion at first/last node.
  * `while(current!=NULL)` and `while(ptr->next!=NULL)` logic.


### Day 4: Circular Linked Lists (SCLL & DCLL)
  * Singly & Doubly Circular LLs.
  * Tail pointing to head to form a loop.
  * SCLL: Create, Insert, Delete by position/value.
  * DCLL: Creation and Display.
  * `do-while` loop for traversal.
  * Handling last node and loop closure.
  * Extra attention to pointer manipulation for circular links.


### Day 5: Deletion, Search & Sorted Insertion in DCLL
  * Deletion by position and value in DCLL.
  * Search operation.
  * Inserting value in a sorted DCLL.
  * Deleting middle node using Floyd’s (Tortoise & Hare).
  * Tortoise & Hare for mid-node in one traversal.
  * Maintaining sorted order during insertion.
  * Using `start->prev` to get the tail efficiently.


### Day 6 : LeetCode Problem-Solving on Linked Lists
  * Q206: Reverse Linked List
  * Q21: Merge Two Sorted Lists
  * Q876: Middle of LL
  * Q237: Delete Node (given only node)
  * Q19: Remove Nth Node from End
  * Q234: Palindrome LL
  * Q83: Remove Duplicates from Sorted LL
  * Q141: Detect Cycle (Floyd’s)

  Learning Outcome:
  * Optimized in-place techniques.
  * Deep understanding of pointer manipulation.
  * Real-world problems using clean modular code with `ListNode` struct.


### Day 7 : Advanced LeetCode Linked List Problems
  * Q2: Add Two Numbers (Optimal)
  * Q160: Intersection of Two LLs
  * Q61: Rotate List
  * Q143: Reorder List
  * Q142: Detect Start of Cycle
  * Q148: Sort LL (Merge sort technique)

  Conceptual Focus:
  * Efficient handling of edge cases.
  * Deep use of Floyd’s algorithm.
  * Combination of multiple operations: reverse + merge, or detect + reposition.


### Day 8 Overview: STL + Odd-Even LL Logic
  * Q328: Odd Even Linked List — segregating odd-indexed and even-indexed nodes efficiently.

  * STL Practice:
    * `std::list` (Doubly LL), `std::forward_list` (Singly LL).
    * Covered insertion, deletion, traversal, sorting, merging.
    * Emulated circular list traversal with `std::list`.
    * Using `auto`, `advance()`, iterators for STL-based LLs.
    * Efficient list operations using C++ STL.

