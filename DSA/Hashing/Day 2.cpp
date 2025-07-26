// LOAD FACTOR
/*
A hash table is like a row of boxes (buckets).
We keep putting items (keys) in those boxes.

Load Factor tells us:
👉 How full are these boxes compared to how many boxes we have?  
   Load Factor is simply how full your hash table is [When it gets too full, we resize and rehash]

              Number of buckets
Load Factor = ______________________
              Number of items stored
​
 
let's understand with example:

 Suppose you have 10 buckets:
  i. If you store 3 items:
     Load Factor = 3/10 = 0.3 
    👉 Table is mostly empty → good performance.
  
 ii. If you store 8 items:
    Load Factor = 8/10 = 0.8
    👉 Table is getting full → more collisions → still okay but keep an eye.
  
iii. If you store 15 items:
     Load Factor = 15/10 = 1.5
    👉 Too full! Collisions everywhere → time to rehash (make a bigger table).
  
  
Q) Why care about load factor?
    Small load factor (like 0.3):
    Very fast lookups, fewer collisions.
    Big load factor (like 0.9):
    More collisions, slower lookups.

Most libraries keep load factor around 0.75 before rehashing.
*/



// REHASHING
/*
When table becomes too full (load factor too high), we create a bigger table and put all old elements into new positions.

Ex: Table size = 5, elements = 5 → load factor = 1 (too full!)
    We create a new table with size = 10.
    We re-insert all elements using hash function for size 10.
    
    👉 Why?
        - To reduce collisions.
        - To make sure time stays O(1) on average.
  
 */ 
  
// When you use built‑in containers like unordered_map or unordered_set in C++… they already handle load factor & 
// automatically rehash (increase bucket count) when load factor crosses a threshold (usually 0.75).
  
  
  
  
