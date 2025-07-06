// 232. Implement Queue using Stacks
// (will use two stacks 2nd stack will have elements in reverse order i.e. in queue format)
class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val=s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */







// 933. Number of Recent Calls
/*
Store each ping time in a queue.
Each time ping(t) is called:
->Add t to the queue.
->Remove all times from the front of the queue that are < t - 3000 [only keep the pings where time is between t - 3000 and t]
->Return the size of the queue (which gives you how many pings are in range)
*/
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {   
    }
    
    int ping(int t) {
        q.push(t);
        while(!q.empty() && q.front()<t-3000){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */







// 622. Design Circular Queue
/*
class MyCircularQueue {
     queue<int>q;
     int size;
public:
    MyCircularQueue(int k) {
       size=k;
    }
    
    bool enQueue(int value) {
        if(q.size()==size) return false;
        q.push(value);
        return true;
    }
    
    bool deQueue() {
        if(q.empty()) return false;
        q.pop();
        return true;
    }
    
    int Front() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if(q.empty()) return -1;
        queue<int> q1=q;
        while(q1.size()>1){
            q1.pop();
        }
        return q1.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        if(q.size()==size) return true;
        return false;
    }
};
*/
//optimal
// (for circular queue  -> we'll use vector (increment front and rear by wraping it around the capacity of vector)) 
class MyCircularQueue {
    vector<int>q;
    int f,r,size,capacity;
public:
    MyCircularQueue(int k) {
        q.resize(k);
        f=0;
        r=0;
        size=0;            //Number of elements currently in the queue
        capacity=k;        //Max size of the queue
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        q[r]=value;
        r=(r+1)%capacity;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        f=(f+1)%capacity;
        size--;
        return true;

    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[(r-1+capacity) % capacity];   //gets the index of the last inserted element, even if rear is 0.
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */






// 225. Implement Stack using Queues
// (reversing all elements while pushing[ so now they are in stcak format])
class MyStack {
    queue<int> q;
public:
    MyStack() {      
    }
    
    void push(int x) {
        q.push(x);
        int s=q.size();
        for(int i=0;i<s-1;i++){   //push all elements from the queue to the queue again by deleting them from front [except the recent one]
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int val=q.front();
        q.pop();
        return val;

    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */






// 387. First Unique Character in a String
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26,0);
        queue<int> q;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;  //storing frequency of ecah char (a is at 0 , b is at 1 and so on..)
            q.push(i);         //store index
            while(!q.empty() && freq[s[q.front()]-'a']>1){    //if freq of element at idx[q.front()] > 1 remove that
                q.pop();
            }
        }
        if(!q.empty()) return q.front();
        return -1;
    }
};

// optimal using vector

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);  //at all 26 indexes, it will store the count of occurence for each char
        for(char ch : s){
            v[ch-'a']++;
        }
      
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a']==1) return i;   //frequncy of the first ever char from the string == 1 , return that index
        }
        return -1;    
    }
};


