// 451. Sort Characters By Frequency
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;  //storing frequency of each char in string 
        }
        priority_queue<pair<int,char>> maxHeap;
        for(auto &p:freq){    //in max Heap store .second[frequency] before .first[char]  (so that it arranges the values acc to frequency )
            maxHeap.push({p.second,p.first});
        }
      //maxHeap will have the most frequent char before than less frequent ones
        string res="";
        while(!maxHeap.empty()){
            int count=maxHeap.top().first;  //(.first in maxHeap is frequency )
            char ch=maxHeap.top().second;   //(.second in maxHeap is char )
            maxHeap.pop();                  //keep deleting
            res.append(count,ch);           //an store char in res with frequency no. of times   [append (count, char)]
        }
        return res;
    }
};







// 692. Top K Frequent Words
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,string> &a, const pair<int,string> &b){ //returns true  1.if frequuency of a is higher  2.if string a is smaller in alphabetical order
            if(a.first==b.first) return a.second < b.second;
            return a.first > b.first;   
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string s: words){
            freq[s]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> minHeap;
        /*priority_queue<pair<int,string>, vector<pair<int,string>>, Compare > minHeap;
                         type of elements | underlying container   | custom comparator   */
        
        for(auto &p:freq){
            minHeap.push({p.second,p.first});
            if(minHeap.size()>k) minHeap.pop();
        }
        vector<string> v;
        while(!minHeap.empty()){
            v.push_back(minHeap.top().second);
            minHeap.pop();
        }
       
        reverse(v.begin(),v.end());
        return v;
    }
};
/*using min Heap to keep minimum frequency element on top (so that when popped minimum frequency gets deleted) 
By default, priority_queue in C++ is a max‑heap (it puts largest on top). but here we want min-heap with special rules:
If frequencies are different → smaller frequency should be on top (so it gets removed first when size > k).
If frequencies are same → lexicographically larger word should be on top (because we want smaller word to stay).
To teach priority_queue this rule, we write a struct Compare with a special function operator().

👉 By creating struct Compare, we teach the heap how to order elements.
👉 This struct is passed as the third template parameter of priority_queue.

operator() means: when you “call” a Compare object like a function, run this code.
We don’t call it manually.
👉 The priority_queue calls this operator internally whenever it needs to compare two elements.

Internally, priority_queue does this automatically.
Compare cmp;
cmp(a,b);  // calls operator()


Condition logic inside:

If frequencies are equal (a.first == b.first):
return a.second < b.second;
👉 If a.second (the word) is alphabetically smaller, we return true (means a is “greater” in min‑heap sense, so b should come first).

Otherwise: return a.first > b.first;
👉 The pair with higher frequency should come before, so we return true if a’s frequency is larger.
*/












