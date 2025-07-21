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





















