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



// # HashMap (key → value)
//    ✅ Use when:
//    You need to store key–value pairs.
//    You want to count frequencies.
//    You need to quickly get a value by key.
//    Example problems:
//    ✔️ Two Sum
//    ✔️ Subarray Sum Equals K
//    ✔️ Group Anagrams

   // Creation:
     #include <unordered_map>
      unordered_map<string, int> hash_map;
      hash_map["apple"] = 5;
      hash_map["banana"] = 7;
      cout << hash_map["apple"]; // 5
      hash_map.erase("banana");
/*
| Operation               | Syntax                                         | Example                                        |
| ----------------------- | ---------------------------------------------- | ---------------------------------------------- |
| ✅ **Insert**          | `m[key] = value;` or `m.insert({key, value});` | `m["apple"] = 5;`                              |
| ✅ **Access value**    | `m[key]`                                       | `cout << m["apple"];`                          |
| ✅ **Find key**        | `m.find(key)` (returns iterator)               | `if(m.find("apple") != m.end()) { found }`     |
| ✅ **Erase key**       | `m.erase(key);`                                | `m.erase("apple");`                            |
| ✅ **Size**            | `m.size()`                                     | `cout << m.size();`                            |
| ✅ **Clear all**       | `m.clear()`                                    | `m.clear();`                                   |
| ✅ **Iterate**         | `for(auto &p : m)`                             | `cout << p.first << " " << p.second;`          |
| ✅ **Check existence** | `m.count(key)`                                 | `if(m.count("apple")){}`                       |
*/



// # HashSet (unique elements only)
//    ✅ Use when:
//    You just care about existence, not values.   Only keys (no values)
//    You need to check duplicates quickly.
//    You want to store only unique elements.
//    Example problems:
//    ✔️ Longest Consecutive Sequence
//    ✔️ Detect Cycle in Graph (visited set)
//    ✔️ Check if pair with sum exists

   // Creation:
     #include <unordered_set>
      unordered_set<string> hash_set;
      hash_set.insert("apple");
      hash_set.insert("banana");
      if(hash_set.find("apple") != hash_set.end()) {
          cout << "exists";
      }
      hash_set.erase("banana");
/*
| Operation             | Syntax             | Example                                  |
| --------------------- | ------------------ | ---------------------------------------  |
| ✅ **Insert**          | `s.insert(key);`   | `s.insert(10);`                         |
| ✅ **Find key**        | `s.find(key)`      | `if(s.find(10)!=s.end()) {found}`       |
| ✅ **Erase key**       | `s.erase(key);`    | `s.erase(10);`                          |
| ✅ **Size**            | `s.size()`         | `cout << s.size();`                     |
| ✅ **Clear all**       | `s.clear()`        | `s.clear();`                            |
| ✅ **Iterate**         | `for(auto &x : s)` | `cout << x;`                            |
| ✅ **Check existence** | `s.count(key)`     | `if(s.count(10)) { exists }`            |
*/




// Hash Map (unordered_map)
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<int> arr={2,3,4,2,4,4,1};
    unordered_map<int,int> freq;

    for(int n: arr){
        freq[n]++;
    }

    for(auto &p: freq){
        cout<<"Element: "<<p.first<<" has frequency: "<<p.second<<endl;
    }
}




// Hash Set (unordered_set)
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    vector<int> arr={2,4,3,5,5,2};
    unordered_set<int> s;
    bool duplicate=false;

    for(int n:arr){
        if(s.find(n) != s.end()){
            duplicate=true;
            break;
        }
        s.insert(n);
    }
    cout<<(duplicate ? "Duplicate found " : "No duplicate found");
}





//HASHING: 
#include<iostream>
#include<vector>
#include<list>
using namespace std;

const int size=10;
// vector<vector<int>> hashTable(size);   //can use this but while removing element from middle, it will take O(n) becuase it shifts elements
vector<list<int>> hashTable(size);   //using list so that we can use .remove()  and so each buckt holds a chain 

void insert(int key){
    int idx = key % size;
    hashTable[idx].push_back(key);
}

bool search(int key){
    int idx = key % size;
    for(int a: hashTable[idx]){
        if(a == key) return true;
    }
    return false;
}

void deleteItem(int key){
    int idx = key % size;
    hashTable[idx].remove(key);
}

void display(){
    for(int i=0;i<size;i++){
        cout<<i<<": ";
        for(int a: hashTable[i]) cout<< a <<" ";
        cout<<endl;
    }
}

int main(){
    insert(15);
    insert(18);
    insert(35);
    insert(2);
    insert(9);

    display();

    cout<<"Searching 25: "<<(search(35) ? "Found" : "not found")<<endl;
    
    deleteItem(2);
    display();

}

/*list is a container from the C++ Standard Template Library (STL).
 It stores elements in a doubly‑linked list internally.
 Key properties of list:
✅ Insertion and deletion at any position is O(1) (just relink pointers).
✅ But random access (like list[i]) is not direct; you have to iterate.
✅ It keeps elements in the order they were inserted.*/






//Hashing using Linked List
#include<iostream>
using namespace std;

const int size=10;  //size of hash table

struct Node{   //Node for storing eaxh key at bucket
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

Node *hashTable[size]; //Making hashTable of defined size

int hashFunction(int key){   //finding index
    return key%size;
}

void insert(int key){
    int idx=hashFunction(key);    //find index
    Node *newnode= new Node(key);   //make memory for key 
    newnode->next=hashTable[idx];   //store the value at hashTable in next of node [NULL will stored in starting]
    hashTable[idx]=newnode;         //and now store  the node(key) at that index in hashTable
}

int search(int key){
    int idx=hashFunction(key);
    Node *temp=hashTable[idx];
    while(temp!=NULL){
        if(temp->data==key) return idx;
        temp=temp->next;
    }
    return -1;

}

void deleteKey(int key){
    int idx= hashFunction(key);
    Node* temp=hashTable[idx];
    Node *prev=NULL;  //maintaining a previous pointer

    while(temp!=NULL){
        if(temp->data == key){
            if(prev==NULL){
                hashTable[idx]=temp->next;
            }
            else{
                prev->next=temp->next;
            }
            delete temp;
            cout<<"Deleted "<<key<<endl;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    cout<<key<<" not found"<<endl;
}

void display(){
    cout<<"Hash Table is: \n";

    for(int i=0;i<size;i++){
        cout<<i<<": ";
        Node *temp=hashTable[i];
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
}


int main(){
    //initialisation
    for(int i=0;i<size;i++) hashTable[i]=NULL;

    //insertion 
    insert(17);
    insert(34);
    insert(3);
    insert(22);
    insert(47);
    insert(88);
    insert(92);

//  (index 2) ---> Node(92) ---> Node(22) ---> NULL

    display();

    //searching
    int i=search(22);
    if(i==-1) cout<<"key not found "<<endl;
    else cout<<"key found at "<<i<<endl;

    //deletion
    deleteKey(17);

    //display
    display();

}

/*
HashTable (array of heads):
+-----+-----+-----+-----+-----+-----+-----+-----+-----+----+
|  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9 | 
+-----+-----+--|--+--|--+--|--+-----+-----+--|--+--|--+----+
               |     |     |                 |     |
               v     v     v                 v     v
              [92]  [3]   [34]              [47]  [88]
               |     |     |                 |     |
               v     v     v                 v     v
              [22]   NULL  NULL             [17]   NULL
               |                             | 
               v                             v
              NULL                          NULL
*/


/*Linked List in each bucket handles collision | dynamic size per bucket | Each node points to next node (next)*/

/* For insertion:
In bucket 2:
hashTable[2] stores the pointer to the first node.

Each node has a next pointer linking to the next node.

Last node’s next is NULL
*/

/*for searching: go to that index and traverse all the nodes at that index */

/*for deletion: just relink the next pointer*/

