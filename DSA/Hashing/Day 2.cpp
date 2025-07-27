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




// Backend of built-in hashing( unordered_map / unordered_set )
/*
unordered_map<int,string> m;
m[5] = "apple";

Buckets: internally keeps an array of buckets (like vector<list<pair<K,V>>>).
Hash function: automatically provided (e.g., std::hash<int>).
Load factor: it tracks how full the table is.
Rehashing: when load factor > 0.75, it automatically doubles bucket size and moves elements.
Collision handling: uses SEPARATE CHAINING (list per bucket).

Each bucket is a chain (usually a linked list or sometimes a tree for very high collisions).
*/



// Backend of manual hashing
/*
vector<list<int>> hashTable(size);

Think of the vector as the array of buckets. Each element of that vector is a list<int>, which represents a chain for that bucket.

Buckets: you create an array (vector) of chains (list<int> or vector<int>).
Hash function: you design, e.g. idx = key % size.
Load factor: you have to calculate (elements / buckets) manually.
Rehashing: you have to write code to create a new bigger table and move elements.
Collision handling: you choose method:
  - Separate chaining (list per bucket)
  - Open addressing (linear probing, etc.)
  
*/




// For COLLISION handling we'll use Linear Probing and Quadratic Probing
// Division method and Mid-Sqaure method are one of the ways to define a hash fucntion [a way to store values in hash table]

// LINEAR PROBING using DIVISION method
#include<iostream>
using namespace std;
const int size=10;
int hashTable[size];

int main(){
    int k,key;
    
    for(int i=0 ;i<size;i++){
        hashTable[i]={-1};
    }

    cout<<"Enter the no. of elements: ";
    cin>>k;

    cout<<"Enter elements: ";
    for(int i=0 ;i<k;i++){
        cin>>key;
        int idx=key % size;   //division [find index]
        if(hashTable[idx]==-1) hashTable[idx] = key;    //if space is empty --> insert
        else{  //if not empty ---> search for next empty index   COLLISION OCCUR 
            while(hashTable[idx]!=-1){    
                idx++;
                if(idx==size) idx=0;    //if index reaches the end of hash table search from 0th index
            }
            hashTable[idx] = key;
        }
    }
    cout<<"Hash Table is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<i<<": "<<hashTable[i]<<endl;
    }
}
/* Division method(hash fucntion) is used for finding index for insertion. It works by taking the remainder when the key is divided by the table size.*/
/*if part is when there's no collision*/
/*else part is when collision occurs now use linear probing */
/*the while loop part is LINEAR PROBING as we are searching for next empty space to insert new element*/







// SEARCHING and DELETING With Linear Probing using Division method
#include<iostream>
using namespace std;
const int size=10;
int hashTable[size];

void insert(int key){
    int idx=key % size;   //division [find index]
    int start=idx;

    if(hashTable[idx]==-1 || hashTable[idx]==-2) hashTable[idx] = key;    //if space is empty --> insert
        
    else{  //if not empty ---> search for next empty index
        while(hashTable[idx]!=-1 && hashTable[idx]!=-2){    
            idx=(idx+1)%size;  //wraping the idx
            if(idx==start){   //all indexes are traversed
                cout<<"Table is full !! cannot insert";
                return;                   
            }
        }
        hashTable[idx] = key;
    }
}

int search(int key){
    int idx=key%size;
    int start=idx;

    while(hashTable[idx]!=-1){
        if(hashTable[idx]==key) return idx;
        idx=(idx+1)%size;
        if (idx==start) break;  //all indexes are traversed
    }
    return -1;
}


bool deleteKey(int key){
    int idx=key%size;
    int start=idx;

    while(hashTable[idx]!=1){
        if(hashTable[idx]==key){
            hashTable[idx]=-2;   //indicating deleted
            return true;
        }
        idx=(idx+1)%size;
        if (idx==start) break;  //all indexes are traversed
    } 
    return false;
}

void display(){
    cout<<"Hash Table is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<i<<": ";
        if(hashTable[i]==-1) cout<<"empty"<<endl;
        else if(hashTable[i]==-2) cout<<"deleted"<<endl;
        else cout<<hashTable[i]<<endl;
    }
}

int main(){
    int k,key;
    
    //initialisation
    for(int i=0 ;i<size;i++){
        hashTable[i]=-1;
    }

    cout<<"Enter the no. of elements: ";
    cin>>k;

    //insertion
    cout<<"Enter elements: ";
    for(int i=0 ;i<k;i++){
        cin>>key;
        insert(key);
    }
    display();


    //searching
    cout<<"\nEnter a key to search: ";
    cin>>key;
    int j=search(key);
    if(j==-1) cout<<key<<" not found"<<endl; 
    else cout<<key<<" found at index: "<<j<<endl;


    //deletion
    cout<<"Enter a key to delete: ";
    cin>>key;
    cout<<(deleteKey(key)? "key deleted":" key not found, cannot delete");


    display();

}


  
  
  
  

//LINEAR PROBING using MID-SQUARE METHOD
#include<iostream>
using namespace std;
const int size=10;
int hashTable[size];

int main(){
    int k,key;
    
    //initialisation
    for(int i=0 ;i<size;i++){
        hashTable[i]=-1;
    }

    cout<<"Enter the no. of elements: ";
    cin>>k;

    //insertion
    cout<<"Enter elements: ";
    for(int i=0 ;i<k;i++){
        cin>>key;
       //mid-sqaure method for finding index
        int sq = key*key;
        int mid = (sq/10) % 10;
        int idx = mid%size;
        
        if (hashTable[idx]==-1) hashTable[idx]=key;
        else{ //coliision occur --> linear probing
            int start=idx;
            while(hashTable[idx]!=-1){
                idx=(idx+1)%size;
                if (idx==start){
                    cout<<"table full!!";
                    break;
                }
            }
            if(hashTable[idx] == -1) hashTable[idx]=key;
        }
    }

    cout<<"Hash Table is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<i<<": ";
        if (hashTable[i] == -1) cout << "empty"<<endl;
        else cout << hashTable[i]<<endl;
    }

}
/*Mid-Squre Method is used for finding index(hash value) from a key so that the keys are spread out more evenly in a hash table.
take key --> sqaure it --> find some mid portion --> take modulo with table size   */
/*if part is when there's no collision*/
/*else part is when collision occurs   now use linear probing */
/*the while loop part is LINEAR PROBING as we are searching for next empty space to insert new element*/











