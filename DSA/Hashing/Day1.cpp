// HASHING: A technique to map data to a fixed-size value (called a hash), which we use for fast access.

/*
Special technique used for efficient data lookup and retrieve | transforms data into fixed sized values
Imagine putting things in lockers based on a formula → key % 10 tells us where to store it.
eg: k=123  ,  n=10     =>  store at k%n  123 % 10 = 3 [store k (123) at 3rd position in the table of size n ]
Used in: dictionaries, hash maps, password storage, caches, etc.


# Why do we USE Hashing?
It allows: Fast insertion, deletion, and search → average case O(1)
Efficient tracking of frequencies, duplicates, lookups
Fast Access (O(1) average): Instead of searching through the whole list/array (O(n)), hashing lets you jump directly to where your data is stored.
   Key → Value mapping:
   When you have unique keys (like names, IDs, emails) and you want to quickly store and retrieve associated values.
   Great for lookups and counting:  Check if something exists. | Count frequencies. | Find duplicates. | Track seen elements.

Space–time tradeoff: Uses extra memory (for the table) but saves huge time.


WORKING:  Key -> Hash Function -> Index -> Store in Array (called bucket)


HASH FUNCTION 
  just a formula or method (function) that turns a key into a number (index).
  Should be: Fast | Deterministic (same input → same output) | Uniformly distributed
  It is STEP 1 where we use hash function to decide which slot it goes into
  Ex: index = hash("Priya") % 10  -> gives 3
      index = hash("Rahul") % 10  -> gives 7
      index = hash("Sona")  % 10  -> gives 3 (collision!)


HASH TABLE
  The actual data structure (like a box with many slots) that stores your data at positions decided by the hash function.
  A hash table (or hash map) is a data structure that:
  Stores key–value pairs.
  Uses a hash function to map keys to an index in an internal array (bucket array).
  👉 Main idea:
  Key → hash function → index → store value at that index.
  It is STEP 2 where we take those index number and actually store the data in an array like structure (hash table)
  Ex: Table[3] = { ("Priya",9012...), ("Sona",9123...) }  <-- collision handled here (chaining)
      Table[7] = { ("Rahul",9812...) }






WAYS to create Hash:
  A. Hash Functions (ways to create the hash)
  You need a function that converts a key into an index:
  - Division Method:
    index = key % table_size
  
  - Multiplication Method:
    index = floor(table_size * fractional_part(key * A)) (where A is a constant between 0 and 1)
  
  - Folding Method:
    Split the key into parts and combine them (like adding parts of a number).
  
  - Mid‑Square Method:
    Square the key and take some middle bits.
  
  - Custom/Language Hash:
    Built‑in hash() in Python or std::hash in C++.


B. Collision Handling (ways to store in hash table when same index)
    If two keys map to the same index, handle collision using:
    
    1. Open Hashing (Separate Chaining):
    Store a list (chain) at each index.
    
    2. Closed Hashing (Open Addressing):
    Store everything inside the array by finding a new spot:
      - Linear Probing
      - Quadratic Probing
      - Double Hashing





# PROBLEM in Hashing: COLLISION
    When two keys go to the same index, we need a strategy to handle it.
    
    Handling Collisions:
    | Method            | Other Names                      | How it Works                                                |
    | ----------------- | -------------------------------- | ----------------------------------------------------------- |
    | Separate Chaining | Open Hashing / Closed Addressing | Store a chain (linked list) at each bucket                  |
    | Open Addressing   | Closed Hashing / Open Addressing | Find another free slot by probing (linear/quadratic/double) |

  1. Separate Chaining
    Also called open hashing (some books say “closed addressing”).
    At each index, you keep a linked list (or chain) of all elements that hash to that index.
    When collision happens, you just append to that chain.
    Ex: Index 2 -> [key1 → value1] → [key2 → value2]

  2. Open Addressing
    Also called closed hashing (some books say “open addressing”).
    Instead of a chain, all elements are stored directly in the array.
    When a collision happens, you search for another empty slot inside the same table by following a probing sequence.

    Common probing methods:
      - Linear Probing: check next slots one by one: (index + 1) % size, (index + 2) % size, …
      - Quadratic Probing: check with square jumps: index + 1², index + 2², …
      - Double Hashing: use a second hash function to find step size.



# TIME COMPLEXITY
    Operation	               | Best/Average Case  | Worst Case
    Insert/Search/Delete	   |        O(1)	      |   O(n)
    (Worst case happens if all keys collide (bad hash function) )



How do you know when to use Hashing?
✅ Do I need fast insert, search, or delete (ideally O(1))?
👉 Use hashing.

✅ Am I mapping keys to values?
👉 Use a hash map (e.g., counting frequencies, storing data by ID).

✅ Do I need to check existence quickly?
👉 Use a hash set.

✅ Am I solving problems like Two Sum, duplicates, subarray sums, longest sequences?
👉 These are classic hashing problems.

✅ Is order not important, but speed is?
👉 Hashing is perfect because it’s unordered but very fast.



Hash Table DOESN'T guarantee ORDER: 
  When you store keys, the order of insertion is not preserved.
  The internal arrangement depends on the hash function and collisions.

Example in C++:
  unordered_map (hash table) → ❌ no order guarantee.
  map (red‑black tree) → ✅ sorted order.


*/













