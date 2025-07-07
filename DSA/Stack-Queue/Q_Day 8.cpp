// 1700. Number of Students Unable to Eat Lunch
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0 

// approach:
// if student need and sandwich availability is same take it and remove that student ,
// else until the need is satisfied remove student from front and push the student back in queue
// (but if count == q.size()	No one wants the current sandwich → stop [count tracks how many consecutive students have refused the current sandwich at the top of the stack.])
  
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int i=0;
        int count=0;
        while(!q.empty()){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                count=0;     // someone took the sandwich, reset the counter
            }
            else {
                q.push(q.front());
                q.pop();
                count++;    //increase count when student is pushed back 
            }
            if(count==q.size()) break;   //no one wants the current sandwich
        }
        return q.size();     //number of students unable to eat    
    }
};







// 950. Reveal Cards In Increasing Order
// Input: deck = [17,13,11,2,3,5,7]
// Output: [2,13,3,11,5,17,7]
// Explanation: 
// We get the deck in the order [17,13,11,2,3,5,7] (this order does not matter), and reorder it.
// After reordering, the deck starts as [2,13,3,11,5,17,7], where 2 is the top of the deck.
// We reveal 2, and move 13 to the bottom.  The deck is now [3,11,5,17,7,13].
// We reveal 3, and move 11 to the bottom.  The deck is now [5,17,7,13,11].
// We reveal 5, and move 17 to the bottom.  The deck is now [7,13,11,17].
// We reveal 7, and move 13 to the bottom.  The deck is now [11,17,13].
// We reveal 11, and move 17 to the bottom.  The deck is now [13,17].
// We reveal 13, and move 17 to the bottom.  The deck is now [17].
// We reveal 17.
// Since all the cards revealed are in increasing order, the answer is correct.


//aproach:
/* we need to return vector in such a order that at ending the order of revealed card is in ascending order 
that when we see the top card ,remove it and place the 2nd card at the bottom of queue 
to solve we'll think backwards i.e.  (i) sort the vector, (ii)Move last card to the front and (iii)place the new card at the front 

So firstly, Loop through sorted deck from largest to smallest:
If deque is not empty:
Move the last card to front (reverse of putting 2nd card to bottom)
Then insert the current card at front (undo revealing) 
*/
class Solution{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());    // sort the vector
        deque<int> dq;
        for(int i=deck.size()-1;i>=0;i--){
            if(!dq.empty()){
                dq.push_front(dq.back());   //Move last card to the front
                dq.pop_back();
            }
            dq.push_front(deck[i]);     //place the new card at the front 
        }
        vector<int> v(dq.begin(),dq.end());   //make vector v for the elements in deque
        return v;
    }
};






// 649. Dota2 Senate
// In each round, each senator can exercise one of the two rights:
// Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
// Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for(int i=0;i<senate.length();i++){
            if(senate[i]=='R') r.push(i);    //if it is R push index in queue r
            else d.push(i);                  //if it is D push index in queue d
        }
      //compare the front of both queue
        while(!r.empty() && !d.empty()){
            // Radiant senator acts first and bans the Dire senator
            // Push this Radiant back into queue with 'updated index' to simulate future round
            if(r.front() < d.front()) r.push(r.front()+senate.length()); 
              
            // Dire senator acts first and bans the Radiant senator 
            else d.push(d.front()+senate.length()); 

            //remove front from both queue
            r.pop();    
            d.pop();
        }
      //return whichever queue has elements
        if(!r.empty()) return "Radiant";
        return "Dire";
    }
};







// 641. Design Circular Deque
// using vector
/*
class MyCircularDeque {
    vector<int>cd;
    int f,r,size,capacity;
public:
    MyCircularDeque(int k) {
        cd.resize(k);
        f=0;
        r=k-1;
        size=0;
        capacity=k;
    }
    bool insertFront(int value) {
        if(isFull()) return false;
        f=(f-1+capacity)%capacity;  //for wraping around (circular behaviour)
        cd[f]=value;
        size++;
        return true;
    }
    bool insertLast(int value) {
        if(isFull()) return false;
        r=(r+1)%capacity;        //for wraping around (circular behaviour)
        cd[r]=value;
        size++;
        return true;
    }
    bool deleteFront() {
        if(isEmpty()) return false;
        f=(f+1)%capacity;             //for wraping around (circular behaviour)
        size--;
        return true;
    } 
    bool deleteLast() {
        if(isEmpty()) return false;
        r=(r-1+capacity)%capacity;      //for wraping around (circular behaviour)
        size--;
        return true;
    }
    int getFront() {
        if(isEmpty()) return -1;
        return cd[f];
    }
    int getRear() {
        if(isEmpty()) return -1;
        return cd[r];
    }
    bool isEmpty() {
        return size==0;
    }
    bool isFull() {
        return size==capacity;
    }
};
*/
//optimal solution using STL deque
class MyCircularDeque {
    deque<int>cd;
    int size;
public:
    MyCircularDeque(int k) {
        size=k;
    }
    
    bool insertFront(int value) {
        if(cd.size()==size) return false;
        cd.push_front(value);
        return true;

    }
    
    bool insertLast(int value) {
        if(cd.size()==size) return false;
        cd.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(cd.empty()) return false;
        cd.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(cd.empty()) return false;
        cd.pop_back();
        return true;
    }
    
    int getFront() {
        if(cd.empty()) return -1;
        return cd.front();
    }
    
    int getRear() {
        if(cd.empty()) return -1;
        return cd.back();
    }
    
    bool isEmpty() {
        return cd.empty();
    }
    
    bool isFull() {
        return size==cd.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */






// 1701. Average Waiting Time
// Input: customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
// Explanation:
// 1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
// 2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
// 3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
// So the average waiting time = (2 + 6 + 7) / 3 = 5.

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long t=0;
        long long total=0;
        for(auto c:customers){
            int a=c[0];   //arrival time
            int b=c[1];   //cook time
            if(t<a) t=a;   //if the current time < arrival make the time as arrival
    
            t+=b;        //add cook time to current time
            total+=(t-a);    //calculate wating time by current time -arrial time)
        }
        double avg=(double) total/customers.size();
        return avg;
    }
};

