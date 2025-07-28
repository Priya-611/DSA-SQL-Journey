//Quadratic Probing
/*
Quadratic Probing is a collision resolution technique in open addressing where:
👉 If a collision happens, we try positions at: 
    (hash + i²) % size

h, (h + 1²) % size, (h + 2²) % size, (h + 3²) % size, ...

for division method, Hash function: h(key) = key % 10


Linear Probing : h, h+1, h+2, h+3... [it check consecutive slots -> cause primary clustering]
Quadratic Probing : h + 1², h + 2², h + 3²... [It jumps in wider gaps — reduces the chance of clusters. & avoids long chains of filled spots.]
*/


//QUADRATIC PROBING using DIVISION METHOD
#include<iostream>
using namespace std;

const int size=10;
int hashTable[size];

int main(){

    for(int i=0;i<size;i++){
        hashTable[i]=-1;
    }

    int k,key;
    cout<<"Enter the no. of size: ";
    cin>>k;

    cout<<"Enter Elements: ";
    for(int i=0;i<k;i++){
        cin>>key;

        int idx=key%size;  //finding index [DIVISION METHOD]

        if(hashTable[idx]==-1) hashTable[idx]=key;
        else{    //when collision occur , now use QUADRATIC PROBING
            int i=1;
            int h=idx;  //store the position found using divison method (hashValue)
            while(hashTable[idx]!=-1){  //now using that hash value find next index
                idx = (h + i*i)%size;   //finding next empty index 
                i++;
            }
            hashTable[idx]=key;
        }    
    }

    cout<<"Hash Table is: ";
    for(int i=0;i<size;i++){
        cout<<i<<": ";
        if(hashTable[i]==-1) cout<<"empty"<<endl;
        else cout<<hashTable[i]<<endl;
    }

}







// SEARCHING and DELETING using Quadratic Probing with Division method
#include<iostream>
using namespace std;

const int size=10;
int hashTable[size];

void insert(int key){
    int idx=key%size;   //division method to find index
    if(hashTable[idx]==-1 || hashTable[idx]==-2) hashTable[idx]=key;
    else{    //quadratic probing for collision
        int i=1;
        int h=idx;
        while(i<size){
            idx = (h + i*i)%size;
            if(hashTable[idx]==-1 || hashTable[idx]==-2){
                hashTable[idx]=key;
                return;
            }
            i++;
        }
    }        
}

int search(int key){
    int idx=key%size;
    int h=idx;
    int i=1;
    while(hashTable[idx]!=-1 && i<size){
        if(hashTable[idx]==key) return idx;
        idx=(h+i*i)%size;
        i++;
    }
    return -1;
    
}

bool deleteKey(int key){
    int pos=search(key);
    if(pos==-1) return false;
    hashTable[pos]=-2;
    return true;
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

    //initialisation
    for(int i=0;i<size;i++){
        hashTable[i]=-1;
    }

    int k,key;
    cout<<"Enter the no. of size: ";
    cin>>k;

    //insertion
    cout<<"Enter Elements: ";
    for(int i=0;i<k;i++){
        cin>>key;
        insert(key);
    }

    display();

    //Searching
    cout<<"Enter a element to search: ";
    cin>>key;

    int pos=search(key);
    if(pos==-1) cout<<key<<" not found"<<endl;
    else cout<<key<<" found at index : "<<pos<<endl;

    //Deletion
    cout<<"Enter element to delete: ";
    cin>>key;
    cout<<((deleteKey(key))?"deleted": "key not found ");

    //display
    display(); 
}





