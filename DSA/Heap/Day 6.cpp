// 1337. The K Weakest Rows in a Matrix
// Input: mat = 
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]], 
// k = 3
// Output: [2,0,3]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 2 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 2 
// - Row 4: 5 
// The rows ordered from weakest to strongest are [2,0,3,1,4].

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> v;

        for(int i=0;i<mat.size();i++){
            int s=0;
            for(int j=0;j<mat[i].size();j++){
                s+=mat[i][j];      //getting sum for each row in matrix
            }
            v.push_back(s);
        } 
      
        priority_queue <pair<int,int>> maxHeap;
        int i=0;
        for(int n: v){
            maxHeap.push({n,i});      //pushing value as well as i(index) [maxHeap is sorted according to n ]
            i++;
            if(maxHeap.size()>k) maxHeap.pop();
        }
      
        vector<int> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);  //pushing the indexes 
            maxHeap.pop();
        }
      
        reverse(res.begin(),res.end());
        return res;   
    }
};






// 1985. Find the Kth Largest Integer in the Array
// Input: nums = ["3","6","7","10"], k = 4
// Output: "3"
// Explanation:
// The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
// The 4th largest integer in nums is "3".

/*
class Solution{
  string kthLargestNumber(vector<string>& nums, int k) {
      priority_queue<int,vector<int>,greater<int>> minHeap;
      for(string s:nums){
          minHeap.push(stoi(s));
          if(minHeap.size()>k) minHeap.pop();
      }
      return to_string(minHeap.top());
  }
}

//stoi converts a string to a 32‑bit int.
// But in this problem, the numbers in nums can be very large (up to 100 digits), which is way beyond the range of int (or even long long).
// ❌ This leads to overflow and incorrect results.
*/
//optimal solution
class Solution {
public:
    struct cmp{
        bool operator()(const string &a,const string &b){  //defining a comparator operator
           // Compare lengths first
            if(a.size() == b.size()) return a > b;  // same length → lexicographically smaller is smaller number
            return a.size() > b.size();  // shorter length → smaller number
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,cmp> minHeap; //keep the heap for string values only
        for(auto &s:nums){
            minHeap.push(s);
            if(minHeap.size()>k) minHeap.pop();
        }
        return minHeap.top();
    }
};

/*
| Syntax                       | What happens             | Efficiency       | Can modify original? |
| ---------------------------- | ------------------------ | ---------------- | -------------------- |
| `for (auto s : nums)`        | Makes a copy each time   | ❌ slower         | ✅ changes copy only  |
| `for (auto &s : nums)`       | Uses reference (no copy) | ✅ faster         | ✅ modifies original  |
| `for (const auto &s : nums)` | Uses read‑only reference | ✅ fastest & safe | ❌ cannot modify      |

*/





// 658. Find K Closest Elements
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> maxHeap;
        for(int n:arr){
            int dist=abs(n-x);
            maxHeap.push({dist,n});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<int> res;
        while(!maxHeap.empty()){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};






// 264. Ugly Number II
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
    
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> minHeap;
        unordered_set<long> seen;   //to avoid duplicates
        //start with pushing 1 
        minHeap.push(1);
        seen.insert(1);

        long ugly=1;  //let say the fisrt  no. is 1
        for(int i=0;i<n;i++){    //till the loop keeps on running 
    // ugly always stores the smallest ugly number currently available in the heap (and then you remove it).
            ugly=minHeap.top();   //get the top of min Heap (i.e. smallest)
            minHeap.pop();       //pop it out

        //and get next three numbers whose prime factors are limited to 2, 3, and 5.
            long n2=ugly*2;
            long n3=ugly*3;
            long n4=ugly*5;

     //push element in heap only if they are new (i.e. insert().second returns true)    i.e. firstly insert in seen set if it gets inserted then only push in heap
            if(seen.insert(n2).second) minHeap.push(n2);
            if(seen.insert(n3).second) minHeap.push(n3);
            if(seen.insert(n4).second) minHeap.push(n4);

        }
        return (int)ugly;  //convert long ino int 
    }
};
/*
| Iteration (i) | ugly (popped) | heap (after push)                         | seen (after insert)           |
| ------------- | ------------- | ----------------------------------------- | ----------------------------- |
|  0            | 1             | \[2,3,5]                                  | {1,2,3,5}                     |
|  1            | 2             | \[3,4,5,6,10]                             | {1,2,3,4,5,6,10}              |
|  2            | 3             | \[4,5,6,9,10,15]                          | {1,2,3,4,5,6,9,10,15}         |
|  3            | 4             | \[5,6,8,9,10,15,12,20]                    | {1,2,3,4,5,6,8,9,10,12,15,20} |
|  4            | 5             | \[6,8,9,10,15,20,12,25]                   | {…25}                         |
|  5            | 6             | \[8,9,10,12,15,20,25,18,30]               | {…18,30}                      |
|  6            | 8             | \[9,10,12,15,16,18,20,25,30,24,40]        | {…16,24,40}                   |
|  7            | 9             | \[10,12,15,16,18,20,25,27,30,24,40,45]    | {…27,45}                      |
|  8            | 10            | \[12,15,16,18,20,24,25,27,30,40,45,50]    | {…50}                         |
|  9            | 12            | \[15,16,18,20,24,25,27,30,36,40,45,50,60] | {…36,60}                      |
*/
// after the loop, ugly = 12, which is the 10th ugly number.


/*
A set is a container that stores unique elements.
👉 It automatically takes care of no duplicates.
👉 You don’t need to manually check if an element already exists.

std::set    Stores elements in sorted order.
std::unordered_set      Stores elements in no particular order (hash table).

*)  seen.insert()
    What does insert() return?
    -> pair<iterator, bool>
That means:
result.first → an iterator pointing to the element in the set.
result.second → a bool telling you if insertion actually happened.

whenever there's a new element(never seen before) it gets inserted and .second returns true
whenever there's a repeated element(already existing) it do not get inserted and .second returns false
*/

