// 560. Subarray Sum Equals K
// Input: nums = [1,2,3], k = 3
// Output: 2
 
 class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;    //sum: no.of times
        mp[0]=1;   //base case, as sum=0 as appeared only once 
        int sum=0,count=0;
        for(int n:nums){
            sum+=n;     // keep running total
            if(mp.count(sum-k)){    //if sum-k has appeared before in the map add in count
                count+=mp[sum-k];      // how many times we've seen (sum - k)
            }
            mp[sum]++;     // update current sum frequency
        }
        return count;
    }
};

/*
 Example:
nums = [1, 2, 1], k = 3
Let's track:
sum = 0
mp = {0:1}    

Step-by-step:
num = 1 → sum = 1
sum - k = 1 - 3 = -2 → not in map → nothing to count
mp = {0:1, 1:1}

num = 2 → sum = 3
sum - k = 3 - 3 = 0 → YES! It's in the map          [after a point the sum will be equal to k so the sum-k will be 0 and we'll add
So one subarray with sum 3 ends here      subarray =[1,2]
count = 1
mp = {0:1, 1:1, 3:1}

num = 1 → sum = 4
sum - k = 4 - 3 = 1 → YES!
So another subarray found        sunarray=[2,1]
count = 2
*/






// 219. Contains Duplicate II
// return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Input: nums = [1,2,3,1], k = 3
// Output: true
  
// Example 2:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            if(s.count(nums[i])) return true;   //if element already exists return true
            s.insert(nums[i]);    //else insert in set
            if(s.size()>k){
                s.erase(nums[i-k]);    // Remove the element that's now outside the window
            }
        }
        return false;
    }
};







// 187. Repeated DNA Sequences
// given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
// You may return the answer in any order.

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: ["AAAAACCCCC","CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;
        for(int i=0;i+9<s.length();i++){   // loop goes on and pick 10 letter
            string sub=s.substr(i,10);  //picks every 10 letter window
            if(seen.count(sub)){  //if substring already exists add in result
                res.insert(sub);
            }
            else{   //if substring is appearing for the first time insert it it seen 
                seen.insert(sub);
            }
        }
        return vector<string>(res.begin(),res.end());
    }
};


