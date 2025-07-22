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
